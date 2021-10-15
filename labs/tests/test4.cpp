#define CATCH_CONFIG_MAIN

#include "../src/Notes.hpp"
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

TEST_CASE("Testing Notes") {
    Date d1(12,12,2021,9,13,54);
    d1.setDateTime();
    Notes n(d1, "new note");
    char *s1 = new char[28];
    sprintf(s1, "%s", n.getNote());
    REQUIRE(!memcmp(s1, n.getNote(), 28));
}