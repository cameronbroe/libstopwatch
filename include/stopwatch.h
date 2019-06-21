//
// Created by cameron on 6/20/19.
//

#ifndef LIBSTOPWATCH_STOPWATCH_H
#define LIBSTOPWATCH_STOPWATCH_H

#include <thread>
#include <map>
#include <functional>
#include <atomic>

namespace libstopwatch {

    class Stopwatch {
    private:
        std::thread m_thread;
        std::map<uint64_t, std::function<void()>> m_tasks;
        std::atomic_bool m_running;
        uint64_t m_tick;

        void tick();
    public:
        Stopwatch();
        ~Stopwatch() {}

        void start();
        void stop();
        void reset();

        void add_task(uint64_t timestamp, std::function<void()> task);

    };

}


#endif //LIBSTOPWATCH_STOPWATCH_H
