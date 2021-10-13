#define CATCH_CONFIG_MAIN

#include "../src/HoursUSA.hpp"
#include "catch.hpp"  

TEST_CASE("Testing Hours") {
    Date d(12,12,2021,9,12,43);
    Hours h(d);
    char *s = new char[10];
    strcpy(s, "09AM:12:43");
    Date d1(12,12,2021,21,12,43);
    Hours h1(d1);
    char *s1 = new char[10];
    strcpy(s1, "09PM:12:43");
    bool isEqual = !memcmp(s, h.getHours(), 10) && !memcmp(s1, h1.getHours(), 10);
    REQUIRE(isEqual);

}