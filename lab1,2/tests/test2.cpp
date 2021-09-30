#define CATCH_CONFIG_MAIN

#include "../src/date.hpp"
#include "catch.hpp"  

TEST_CASE("Testing days & hours addition()") {
    Date d1(31, 12, 2021, 23, 11, 23);
    Date d2(29, 9, 2021, 12, 5, 4);
    int sumDays = addition(d1, d2, 'd');
    int sumHours = addition(d1, d2, 'h');
    REQUIRE(sumDays == 60);
    REQUIRE(sumHours == 35);
}

TEST_CASE("Testing days & hours subtraction()") {
    Date d1(31, 12, 2021, 23, 11, 23);
    Date d2(29, 9, 2021, 12, 5, 4);
    int subtrDays = subtraction(d1, d2, 'd');
    int subtrHours = subtraction(d1, d2, 'h');
    REQUIRE(subtrDays == 2);
    REQUIRE(subtrHours == 11);
}

TEST_CASE("Testing Date operator+") {
    Date d1(1,1,1,1,1,1);
    Date d2(2,2,2,2,2,2);
    Date d3 = d1 + d2;
    REQUIRE(d3.getDay() == d1.getDay() + d2.getDay());
    REQUIRE(d3.getMonth() == d1.getMonth() + d2.getMonth());
    REQUIRE(d3.getYear() == d1.getYear() + d2.getYear());
    REQUIRE(d3.getHour() == d1.getHour() + d2.getHour());
    REQUIRE(d3.getMinute() == d1.getMinute() + d2.getMinute());
    REQUIRE(d3.getSecond() == d1.getSecond() + d2.getSecond());
}

TEST_CASE("Testing Date operator-") {
    Date d2(2,2,2,2,2,2);
    Date d1(1,1,1,1,1,1);
    Date d4 = d2 - d1;
    REQUIRE(d4.getDay() == d2.getDay() - d1.getDay());
    REQUIRE(d4.getMonth() == d2.getMonth() - d1.getMonth());
    REQUIRE(d4.getYear() == d2.getYear() - d1.getYear());
    REQUIRE(d4.getHour() == d2.getHour() - d1.getHour());
    REQUIRE(d4.getMinute() == d2.getMinute() - d1.getMinute());
    REQUIRE(d4.getSecond() == d2.getSecond() - d1.getSecond());
}

// TEST_CASE("Testing operator=") {
//     Date d1(31, 12, 2021, 23, 11, 23);
//     Date d2;
//     d2 = d1;
//     REQUIRE(d1.getDay() == d2.getDay());
//     REQUIRE(d1.getMonth() == d2.getMonth());
//     REQUIRE(d1.getYear() == d2.getYear());
//     REQUIRE(d1.getHour() == d2.getHour());
//     REQUIRE(d1.getMinute() == d2.getMinute());
//     REQUIRE(d1.getSecond() == d2.getSecond());
// }

