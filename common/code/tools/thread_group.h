#ifndef __THREAD_GROUP_H__
#define __THREAD_GROUP_H__

#include "ext_head.h"
#include <functional>

class ThreadGroup
{
    public:
        ThreadGroup() {}
        ~ThreadGroup() {}

    public:
        template<typename funcT>
        int createThread(funcT func)
        {
            std::lock_guard<std::mutex> lock(thread_mutex_);
            thread_vec_.emplace_back(func);
            return 0;
        }

        size_t size();
        void joinAll();

    private:
        std::vector<std::thread> thread_vec_;
        std::mutex thread_mutex_;
};

#endif // __THREAD_GROUP_H__