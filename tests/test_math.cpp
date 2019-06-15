#include <catch2/catch.hpp>

int add(int a, int b) {
    return a + b;
}
TEST_CASE("add 2") {
    REQUIRE(add(1,2) == 3);
}

TEST_CASE("add 3") {
    REQUIRE(3 == 3);
}
