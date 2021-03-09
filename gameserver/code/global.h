#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "ext_head.h"
#include "hnet/http_client/async_http_client_mgr.h"

class Global
{
    public:
        static AsyncHttpClientMgr async_http_client_mgr;

    public:
        static sig_atomic_t shutdown;   // 关闭服务
};
#endif // __GLOBAL_H__