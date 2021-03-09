#include "http_client.h"

std::mutex HttpClient::curl_init_mutex_;
bool HttpClient::is_init_global_curl_ = false;

void HttpClient::initCurlGlobal()
{
    if (!is_init_global_curl_)
    {
        std::lock_guard<std::mutex> lock(curl_init_mutex_);
        if (!is_init_global_curl_)
        {
            curl_global_init(CURL_GLOBAL_DEFAULT);
            is_init_global_curl_ = true;
        }
    }
}

HttpClient::HttpClient()
{
    HttpClient::initCurlGlobal();
}

HttpClient::~HttpClient()
{
}

int HttpClient::request(string host)
{
    printf("request host:%s\n", host.c_str());
    CURL* curl_ptr = curl_easy_init();
    if (nullptr == curl_ptr)
    {
        printf("curl init error");
        return -1;
    }

    curl_easy_setopt(curl_ptr, CURLOPT_URL, host.c_str());
    CURLcode res = curl_easy_perform(curl_ptr);
    if (res != 0)
    {
        printf("curl perform retcode=%u", res);
    }
    curl_easy_cleanup(curl_ptr);
    return 0;
}
