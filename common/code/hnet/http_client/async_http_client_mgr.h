#ifndef __ASYNC_HTTP_CLIENT_MGR_H__
#define __ASYNC_HTTP_CLIENT_MGR_H__

#include "ext_head.h"
#include <curl/curl.h>
#include "tools/thread_group.h"
#include "http_client.h"

class AsyncHttpClientMgr
{
    public:
        AsyncHttpClientMgr() {}
        ~AsyncHttpClientMgr() {}

    public:
        int init(unsigned int thread_num);
        int start();
        int stop();
        int fini();

    public:
        void workThread(int thread_idx);
    
    public:
        int addRequest(string host);

    private:
        CURLM* multi_curl_ptr_;

        bool is_run_;
        int thread_num_;

        ThreadGroup thread_group_;
};

#endif  // __ASYNC_HTTP_CLIENT_MGR_H__