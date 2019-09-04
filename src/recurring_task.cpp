//
// Created by Cameron Roe on 2019-09-04.
//

#include <iostream>
#include "../include/recurring_task.h"

void stopwatch::RecurringTask::set_last_tick_ran(uint64_t new_tick) {
    this->m_last_tick_ran = new_tick;
}

void stopwatch::RecurringTask::set_task(std::function<void()> task) {
    this->m_task = std::move(task);
}

void stopwatch::RecurringTask::set_frequency(uint64_t frequency) {
    this->m_frequency = frequency;
}

bool stopwatch::RecurringTask::should_be_ran(uint64_t current_tick) {
    return (current_tick - this->m_last_tick_ran >= this->m_frequency);
}

void stopwatch::RecurringTask::run_task() {
    this->m_task();
}
