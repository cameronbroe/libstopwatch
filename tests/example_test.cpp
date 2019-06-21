#include <catch2/catch.hpp>
#include "example.h"

TEST_CASE("2: Testing example", "[multi-file:2]") {
    shared_lib::example obj_example;
    obj_example.setMessage("Hello world!");
    REQUIRE(obj_example.getMessage() == "Hello world!");
}
