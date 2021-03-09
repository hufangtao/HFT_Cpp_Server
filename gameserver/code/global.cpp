#include "global.h"

AsyncHttpClientMgr Global::async_http_client_mgr;
sig_atomic_t Global::shutdown = 0;