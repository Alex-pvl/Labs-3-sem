#define CATCH_CONFIG_MAIN

#include "../src/Notes.hpp"
#include "catch.hpp"  

TEST_CASE("Testing Notes") {
    Date d1(12,12,2021,9,13,54);
    d1.setDateTime();
    Notes n(d1, "new note");
    char *s1 = new char[28];
    sprintf(s1, "%s\n%s", d1.getDateTime(), "new note");
    REQUIRE(!memcmp(s1, n.getNote(), 28));
}