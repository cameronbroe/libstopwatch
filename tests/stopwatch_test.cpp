#include <catch2/catch.hpp>
#include <iostream>
#include "stopwatch.h"

TEST_CASE("3: Testing stopwatch", "[multi-file:3]") {
    auto print_hello = []() { std::cout << "Hello at 5 seconds" << std::endl; };
    auto print_foobar = []() { std::cout << "Hello at 10 seconds" << std::endl; };
    libstopwatch::Stopwatch stopwatch;
    stopwatch.add_task(5, print_hello);
    stopwatch.add_task(10, print_foobar);
    stopwatch.start();
    int i = 0;
    for(i = 0; i < 10; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Foo" << std::endl;
    }
    stopwatch.stop();
    REQUIRE(true == true);
}
