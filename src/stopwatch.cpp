//
// Created by cameron on 6/20/19.
//

#include "../include/stopwatch.h"
#include <iostream>
#include <future>

void stopwatch::Stopwatch::tick() {
    while(this->m_running) {
        if(this->m_single_tasks.count(this->m_tick) > 0) {
            auto task = this->m_single_tasks[this->m_tick];
            std::async(std::launch::async, [&task]() {
                task();
            });
        }

        std::for_each(this->m_recurring_tasks.begin(), this->m_recurring_tasks.end(), [this](RecurringTask& task) {
            if (task.should_be_ran(this->m_tick)) {
                task.set_last_tick_ran(this->m_tick);
                std::async(std::launch::async, [&task]() {
                    task.run_task();
                });
            }
        });
        this->m_tick++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void stopwatch::Stopwatch::start() {
    this->m_thread = std::thread(&stopwatch::Stopwatch::tick, this);
    this->m_running = true;
    this->m_thread.detach();
}

stopwatch::Stopwatch::Stopwatch() {
    this->m_running = false;
    this->m_tick = 0;
}

void stopwatch::Stopwatch::stop() {
    this->m_running = false;
    this->m_tick = 0;
}

void stopwatch::Stopwatch::reset() {
    this->stop();
    this->start();
}

void stopwatch::Stopwatch::add_single_task(uint64_t timestamp, std::function<void()> task) {
    this->m_single_tasks[timestamp] = std::move(task);
}

void stopwatch::Stopwatch::add_recurring_task(uint64_t frequency, std::function<void()> task) {
    RecurringTask new_task;
    new_task.set_last_tick_ran(this->m_tick - frequency);
    new_task.set_task(std::move(task));
    new_task.set_frequency(frequency);
    this->m_recurring_tasks.push_back(new_task);
}
