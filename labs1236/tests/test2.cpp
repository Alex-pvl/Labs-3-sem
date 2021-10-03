#define CATCH_CONFIG_MAIN

#include "../src/Date.hpp"
#include "catch.hpp"  

TEST_CASE("Testing operator+ hours") {
    Date d(31, 12, 2021, 23, 59, 59);
    d = d + 1234;
    d.setDateTime();
    char* arr = new char[19];
    sprintf(arr, "%s", "21.02.2022 09:59:59");
    REQUIRE(!memcmp(arr, d.getDateTime(), 19));
}

TEST_CASE("Testing operator- hours") {
    Date d(31, 12, 2021, 23, 59, 59);
    d = d - 10234;
    d.setDateTime();
    char* arr = new char[19];
    sprintf(arr, "%s", "31.10.2020 13:59:59");
    REQUIRE(!memcmp(arr, d.getDateTime(), 19));
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

TEST_CASE("Testing operator=") {
    Date d1(31, 12, 2021, 23, 11, 23);
    Date d2;
    d2 = d1;
    bool isEqual = (d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth() && d1.getYear() == d2.getYear() 
    && d1.getHour() == d2.getHour() && d1.getMinute() == d2.getMinute() && d1.getSecond() == d2.getSecond());
    REQUIRE(isEqual);
}

