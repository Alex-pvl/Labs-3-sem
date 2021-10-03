#define CATCH_CONFIG_MAIN

#include "../src/Date.hpp"
#include "catch.hpp"  

TEST_CASE("Testing <</>> text") {
    Date d(31,12,2021,12,23,45);
    ofstream out;
    out.open(fileName_txt);
    if (out.is_open()) {
        out << d;
    }
    out.close();
    char* arr = new char[20];
    ifstream in(fileName_txt);
    if (in.is_open()) {
        in.getline(arr, 20);
    }
    in.close();
    d.setDateTime();
    REQUIRE(!memcmp(arr, d.getDateTime(), 19));
}

TEST_CASE("Testing <</>> binary") {
    Date d(31,12,2021,12,23,45);
    ofstream out;
    out.open(fileName_bin);
    if (out.is_open()) {
        out << d;
    }
    out.close();
    char* arr = new char[20];
    ifstream in(fileName_bin);
    if (in.is_open()) {
        in.getline(arr, 20);
    }
    in.close();
    d.setDateTime();
    REQUIRE(!memcmp(arr, d.getDateTime(), 19));
}