#include <catch2/catch.hpp>
#include <iostream>
#include "stopwatch.h"

TEST_CASE("Testing single task stopwatch", "[multi-file:stopwatch]") {
    stopwatch::Stopwatch stopwatch;

    SECTION("should execute a task at 5 ticks") {
        bool five_ticks_ran = false;
        auto five_ticks = [&five_ticks_ran]() {
            five_ticks_ran = true;
        };
        stopwatch.add_single_task(5, five_ticks);
        stopwatch.start();
        std::this_thread::sleep_for(std::chrono::seconds(6));
        stopwatch.stop();
        REQUIRE(five_ticks_ran);
    }

    SECTION("should execute a task at 10 ticks") {
        bool ten_ticks_ran = false;
        auto ten_ticks = [&ten_ticks_ran]() {
            ten_ticks_ran = true;
        };
        stopwatch.add_single_task(10, ten_ticks);
        stopwatch.start();
        std::this_thread::sleep_for(std::chrono::seconds(11));
        stopwatch.stop();
        REQUIRE(ten_ticks_ran);
    }
}

TEST_CASE("Testing recurring task stopwatch", "[multi-file:stopwatch]") {
    stopwatch::Stopwatch stopwatch;

    SECTION("should execute 5 times in 5 ticks") {
        int tick_count = 0;
        auto increment_tick = [&tick_count]() {
            tick_count++;
        };
        stopwatch.add_recurring_task(1, increment_tick);
        stopwatch.start();
        std::this_thread::sleep_for(std::chrono::seconds(5));
        stopwatch.stop();
        REQUIRE(tick_count == 5);
    }
}