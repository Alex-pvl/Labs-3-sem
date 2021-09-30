#define CATCH_CONFIG_MAIN

#include "../src/date.hpp"
#include "catch.hpp"  

TEST_CASE("Testing incYear()") {
    Date d(31, 12, 2021, 23, 59, 59);
    d.incYear();
    REQUIRE(d.getYear() == 2022);
}

TEST_CASE("Testing incMonth()") {
    Date d(31, 12, 2021, 23, 59, 59);
    d.incMonth();
    REQUIRE(d.getMonth() == 1);
    REQUIRE(d.getYear() == 2022);
}

TEST_CASE("Testing incDay()") {
    Date d(31, 12, 2021, 23, 59, 59);
    d.incDay();
    REQUIRE(d.getDay() == 1);
    REQUIRE(d.getMonth() == 1);
    REQUIRE(d.getYear() == 2022);
}

TEST_CASE("Testing incHour()") {
    Date d(31, 12, 2021, 23, 59, 59);
    d.incHour();
    REQUIRE(d.getHour() == 0);
    REQUIRE(d.getDay() == 1);
    REQUIRE(d.getMonth() == 1);
    REQUIRE(d.getYear() == 2022);
}

TEST_CASE("Testing incMinutes()") {
    Date d(31, 12, 2021, 23, 59, 59);
    d.incMinutes();
    REQUIRE(d.getMinute() == 0);
    REQUIRE(d.getHour() == 0);
    REQUIRE(d.getDay() == 1);
    REQUIRE(d.getMonth() == 1);
    REQUIRE(d.getYear() == 2022);
}

TEST_CASE("Testing incSecond()") {
    Date d(31, 12, 2021, 23, 59, 59);
    d.incSecond();
    REQUIRE(d.getSecond() == 0);
    REQUIRE(d.getMinute() == 0);
    REQUIRE(d.getHour() == 0);
    REQUIRE(d.getDay() == 1);
    REQUIRE(d.getMonth() == 1);
    REQUIRE(d.getYear() == 2022);
}

TEST_CASE("Testing decYear()") {
    Date d(1, 3, 2000, 0, 0, 0);
    d.decYear();
    REQUIRE(d.getYear() == 1999);
}

TEST_CASE("Testing decMonth()") {
    Date d(1, 3, 2000, 0, 0, 0);
    d.decMonth();
    REQUIRE(d.getMonth() == 2);
}

TEST_CASE("Testing decDay()") {
    Date d(1, 3, 2000, 0, 0, 0);
    d.decDay();
    REQUIRE(d.getDay() == 29);
    REQUIRE(d.getMonth() == 2);
}

TEST_CASE("Testing decHour()") {
    Date d(1, 3, 2000, 0, 0, 0);
    d.decHour();
    REQUIRE(d.getHour() == 23);
    REQUIRE(d.getDay() == 29);
    REQUIRE(d.getMonth() == 2);
}

TEST_CASE("Testing decMinutes()") {
    Date d(1, 3, 2000, 0, 0, 0);
    d.decMinute();
    REQUIRE(d.getMinute() == 59);
    REQUIRE(d.getHour() == 23);
    REQUIRE(d.getDay() == 29);
    REQUIRE(d.getMonth() == 2);
}

TEST_CASE("Testing decSecond()") {
    Date d(1, 3, 2000, 0, 0, 0);
    d.decSecond();
    REQUIRE(d.getSecond() == 59);
    REQUIRE(d.getMinute() == 59);
    REQUIRE(d.getHour() == 23);
    REQUIRE(d.getDay() == 29);
    REQUIRE(d.getMonth() == 2);
}

TEST_CASE("Testing getCount()") {
    Date d1(1,1,1);
    Date d2(2,2,2);
    Date d3(3,3,3);
    Date d4(4,4,4);
    REQUIRE(d1.getCount() == 4);
}

TEST_CASE("Testing getDateTime()") {
    Date d(31, 12, 2021, 23, 59, 59);
    char ar[20] = "01.01.2022 00:00:00";
    d.incSecond();
    d.setDateTime();
    REQUIRE(!memcmp(d.getDateTime(), ar, 20)); 
}
