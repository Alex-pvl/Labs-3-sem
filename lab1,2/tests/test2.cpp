#define CATCH_CONFIG_MAIN

#include "../src/date.hpp"
#include "catch.hpp"  

TEST_CASE("Testing addition()") {
    Date d1(29, 9, 2021, 14, 46, 30);
    Date d2(13, 10, 2015, 1, 59, 58);
    int sumDays = addition(d1, d2, 'd');
    //int sumHours = addition(d1, d2, 'h');
    REQUIRE(sumDays == 42);
    //REQUIRE(sumHours == 15);
}

