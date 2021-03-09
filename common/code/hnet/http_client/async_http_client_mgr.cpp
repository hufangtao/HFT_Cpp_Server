#include "async_http_client_mgr.h"

int AsyncHttpClientMgr::init(unsigned int thread_num)
{
    if (0 == thread_num)
    {
        return -1;
    }

    thread_num_ = thread_num;
    return 0;
}

int AsyncHttpClientMgr::start()
{
    if (is_run_ || 0 == thread_num_)
    {
        printf("start error, already running\n");
        return -1;
    }

    // 初始化curl global
    HttpClient::initCurlGlobal();
    multi_curl_ptr_ = curl_multi_init();
    
    // 创建线程
    for (int thread_idx = 0; thread_idx < thread_num_; ++thread_idx)
    {
        thread_group_.createThread(std::bind(&AsyncHttpClientMgr::workThread, this, thread_idx));
    }
    is_run_ = true;
    return 0;
}

int AsyncHttpClientMgr::stop()
{
    if (!is_run_)
    {
        printf("not running\n");
        return 0;
    }

    is_run_ = false;
    thread_group_.joinAll();

    // 清理curl global
    return 0;
}

void AsyncHttpClientMgr::workThread(int thread_idx)
{
    if (thread_idx > thread_num_)
    {
        printf("start thread idx = %d error\n", thread_idx);
        return;
    }

    printf("start thread worker, thread idx=%d\n", thread_idx);
    CURLMsg* msg_ptr = nullptr;
    int msgs_left = 0;

    int running_handles = 0;
    while (is_run_)
    {
        curl_multi_perform(multi_curl_ptr_, &running_handles);
        
        // 处理已经完成
        while ((msg_ptr = curl_multi_info_read(multi_curl_ptr_, &msgs_left)))
        {
            if (msg_ptr->msg == CURLMSG_DONE)
            {
                char* url;
                CURL* curl_ptr = msg_ptr->easy_handle;
                curl_easy_getinfo(msg_ptr->easy_handle, CURLINFO_PRIVATE, &url);
                curl_multi_remove_handle(multi_curl_ptr_, curl_ptr);
                curl_easy_cleanup(curl_ptr);
                printf("finish http request\n");
            }
            else
            {
                printf("curl error, msg=%d\n", msg_ptr->msg);
            }
        }
        
        // 全部完成
        if (0 == running_handles)
        {
            usleep(1000);
        }
        else
        {
            usleep(100);
        }
    }
}

int AsyncHttpClientMgr::addRequest(string host)
{
    CURL* curl_ptr = curl_easy_init();
    if (nullptr == curl_ptr)
    {
        printf("curl init error\n");
        return -1;
    }

    curl_easy_setopt(curl_ptr, CURLOPT_URL, host.c_str());
    curl_multi_add_handle(multi_curl_ptr_, curl_ptr);
    printf("add async request succ, host=%s\n",host.c_str());
    return 0;
}
