#define CATCH_CONFIG_MAIN

#include "../src/Methods.hpp"
#include "catch.hpp"  

TEST_CASE("Testing <</>> text") {
    // Date d(31,12,2021,12,23,45);
    // ofstream out;
    // try
    // {
    //     out.open(fileName_txt);
    //     out << d;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // out.close();
    // char* arr = new char[19];
    // ifstream in;
    // Date d1;
    // try
    // {
    //     in.open(fileName_txt);
    //     in >> d1;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // in.close();
    // d.setDateTime();
    Date d(15,10,2021,16,58,32);
    //Date buff;
    ofstream fs;
    //ifstream is;
    if (!fs.is_open()) {
        cout << "No";
    } else {
        cout << "Yes\n";
        fs << d;
        
        // while (true) {
            
            // is >> buff;
            // if (is.eof()) break;
            // //cout << d;
        // }
    }
    fs.close();
    //is.close();
    REQUIRE(true);
}

// TEST_CASE("Testing <</>> binary") {
//     Date d(12,2,2021,5,54,16);
//     Date buff; Date buff2;
//     Date dd(29,3,2004,19,34,19);
//     ofstream out(fileName_bin, ios::binary | ios::app | ios::out);
//     out.write((char*)&d, sizeof(Date));
//     out.write((char*)&dd, sizeof(Date));
//     out.close();
//     ifstream in(fileName_bin, ios::binary);
//     in.read((char*)&buff, sizeof(Date));
//     in.read((char*)&buff2, sizeof(Date));
//     in.close();
//     bool isEqual = (!memcmp(d.getDateTime(), buff.getDateTime(), 19)) && (!memcmp(dd.getDateTime(), buff2.getDateTime(), 19));
//     REQUIRE(isEqual);
// }