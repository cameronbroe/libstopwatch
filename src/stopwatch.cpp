//
// Created by cameron on 6/20/19.
//

#include <stopwatch.h>

#include "../include/stopwatch.h"

void stopwatch::Stopwatch::tick() {
    while(this->m_running) {
        if(this->m_tasks.count(this->m_tick) > 0) {
            auto task = this->m_tasks[this->m_tick];
            task();
        }
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

void stopwatch::Stopwatch::add_task(uint64_t timestamp, std::function<void()> task) {
    this->m_tasks[timestamp] = std::move(task);
}
