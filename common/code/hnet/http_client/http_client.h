#ifndef __HTTP_CLIENT_H__
#define __HTTP_CLIENT_H__

#include "ext_head.h"
#include <curl/curl.h>

class HttpClient
{
    public:
        HttpClient();
        ~HttpClient();

    public:
        int request(string host);
        static void initCurlGlobal();

    public:
        static bool is_init_global_curl_;
        static std::mutex curl_init_mutex_;
};

#endif