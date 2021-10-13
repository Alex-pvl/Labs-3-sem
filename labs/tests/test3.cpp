#define CATCH_CONFIG_MAIN

#include "../src/Methods.hpp"
#include "catch.hpp"  

TEST_CASE("Testing <</>> text") {
    Date d(31,12,2021,12,23,45);
    ofstream out;
    try
    {
        out.open(fileName_txt);
        out << d;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    out.close();
    char* arr = new char[19];
    ifstream in;
    try
    {
        in.open(fileName_txt);
        in.getline(arr, 20);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    in.close();
    d.setDateTime();
    REQUIRE(!memcmp(arr, d.getDateTime(), 19));
}

TEST_CASE("Testing <</>> binary") {
    Date d(31,12,2021,12,23,45);
    d.setDateTime();
    char* arr = new char[19];
    strcpy(arr, d.getDateTime());
    Date buff;
    ofstream out;
    try
    {
        out.open(fileName_bin, ios::binary);
        out.write((char*)&d, sizeof(Date));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    out.close();
    ifstream in;
    try
    {
        in.open(fileName_bin, ios::binary);
        in.read((char*)&buff, sizeof(Date));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    buff.setDateTime();
    char* arr1 = new char[19];
    strcpy(arr1, buff.getDateTime());
    in.close();
    REQUIRE(!memcmp(arr, arr1, 19));
}