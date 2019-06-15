//
// Created by Bang  on 2019-06-13.
//
#include <catch2/catch.hpp>

inline int substraction(int a, int b) {
    return a - b;
}

template<class T>
T add(T a, T b) {
    return a + b;
}

template<class T, int N>
T sum(T a) {
    return a * N;
}

TEST_CASE("sub") {
    REQUIRE(substraction(5, 2) == 3);
    REQUIRE(add<int>(5, 2) == 7);
    REQUIRE(add<double>(5.0, 2.0) == 7.0);
    REQUIRE(sum<int, 2>(5) == 10);
}

