#include "thread_group.h"

size_t ThreadGroup::size()
{
    std::lock_guard<std::mutex> lock(thread_mutex_);
    return thread_vec_.size();
}

void ThreadGroup::joinAll()
{
    std::lock_guard<std::mutex> lock(thread_mutex_);
    for (std::thread& t : thread_vec_)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}