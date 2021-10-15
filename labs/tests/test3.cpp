#define CATCH_CONFIG_MAIN

#include "../src/Methods.hpp"
#include "catch.hpp"  

TEST_CASE("Testing <</>> text") {
    
    REQUIRE(true);
}

TEST_CASE("Testing <</>> binary") {
    Date d(1,2,3,4,5,6);
    Date buff;
    ifstream is;
    readFromBin(is, buff, "text.dat");
    REQUIRE();
}