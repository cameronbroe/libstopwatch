//
// Created by cameron on 6/20/19.
//

#ifndef LIBSTOPWATCH_STOPWATCH_H
#define LIBSTOPWATCH_STOPWATCH_H

#include "recurring_task.h"

#include <thread>
#include <map>
#include <functional>
#include <atomic>
#include <algorithm>

namespace stopwatch {

    class Stopwatch {
    private:
        std::thread m_thread;
        std::map<uint64_t, std::function<void()>> m_single_tasks;
        std::vector<RecurringTask> m_recurring_tasks;
        std::atomic_bool m_running{};
        uint64_t m_tick;

        void tick();
    public:
        Stopwatch();

        void start();
        void stop();
        void reset();

        void add_single_task(uint64_t timestamp, std::function<void()> task);
        void add_recurring_task(uint64_t frequency, std::function<void()> task);
    };

}


#endif //LIBSTOPWATCH_STOPWATCH_H
