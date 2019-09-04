//
// Created by Cameron Roe on 2019-09-04.
//

#ifndef STOPWATCH_RECURRING_TASK_H
#define STOPWATCH_RECURRING_TASK_H

#include <atomic>
#include <vector>
#include <functional>

namespace stopwatch {
    class RecurringTask {
    private:
        std::function<void()> m_task;
        uint64_t m_last_tick_ran;
        uint64_t m_frequency;

    public:
        void set_last_tick_ran(uint64_t new_tick);
        void set_task(std::function<void()> task);
        void set_frequency(uint64_t frequency);

        bool should_be_ran(uint64_t current_tick);

        void run_task();
    };
}

#endif //STOPWATCH_RECURRING_TASK_H
