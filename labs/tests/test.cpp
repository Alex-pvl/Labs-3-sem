#pragma once
#define CATCH_CONFIG_MAIN

#include "../src/Methods.hpp"
#include "../src/Hours.hpp"
#include "../src/Notes.hpp"
#include "../src/Stack.hpp"
#include "../src/Template.hpp"
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
    REQUIRE(d1.getCount() == 16);
}

TEST_CASE("Testing getDateTime()") {
    Date d(31, 12, 2021, 23, 59, 59);
    char* ar = new char[19];
    sprintf(ar, "%s", "01/01/2022 00:00:00");
    d.incSecond();
    d.setDateTime();
    REQUIRE(!memcmp(ar, d.getDateTime(), 19)); 
}

TEST_CASE("Testing operator+ hours") {
    Date d(31, 12, 2021, 23, 59, 59);
    d = d + 1234;
    d.setDateTime();
    char* arr = new char[19];
    sprintf(arr, "%s", "21/02/2022 09:59:59");
    REQUIRE(!memcmp(arr, d.getDateTime(), 19));
}

TEST_CASE("Testing operator- hours") {
    Date d(31, 12, 2021, 23, 59, 59);
    d = d - 10234;
    d.setDateTime();
    char* arr = new char[19];
    sprintf(arr, "%s", "31/10/2020 13:59:59");
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

TEST_CASE("Testing << text") {
    Date d(12,2,2021,12,45,59);
    fstream f("testTxt.txt", fstream::out | fstream::app);
    f << d;
    REQUIRE(f.is_open());
}

TEST_CASE("Testing >> text") {
    Date d(12,2,2021,12,45,59); 
    Date buff; 
    d.setDateTime();
    fstream f("testTxt.txt", fstream::app | fstream::in);
    f >> buff;
    REQUIRE(!memcmp(d.getDateTime(), buff.getDateTime(), 19));
}

TEST_CASE("Testing << binary") {
    Date d(13, 5, 2001, 10, 4, 59);
    ofstream fout("testBinary.dat", ofstream::binary | ofstream::out | ofstream::app);
    writeToBin(fout, d);
    REQUIRE(true);
}

TEST_CASE("Testing >> binary") {
    Date d(13, 5, 2001, 10, 4, 59); 
    Date buff;
    d.setDateTime();
    ifstream fin("testBinary.dat", ifstream::binary | ifstream::in | ifstream::app);
    readFromBin(fin, buff);
    REQUIRE(!memcmp(d.getDateTime(), buff.getDateTime(), 19));
}

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

TEST_CASE("Testing Stack push") {
    Stack st;
    Date d1(15,1,2003,19,25,56);
    Hours d2(d1);
    Notes d3(d1, "new note");
    st.push(d1);
    st.push(d2);
    st.push(d3);
    char *res = new char[80];
    sprintf(res, "%s", "Notes:\n15/01/2003 19:25:56\nnew note\nHours:\n07PM:25:56\nDate:\n15/01/2003 19:25:56\n");
    REQUIRE(!memcmp(res, st.show(), 80));
}

TEST_CASE("Testing Stack pop") {
    Stack st;
    Date d1(15,1,2003,19,25,56);
    Hours d2(d1);
    Notes d3(d1, "new note");
    st.push(d1);
    st.push(d2);
    st.push(d3);
    Date *a = st.pop();
    char *res = new char[44];
    sprintf(res, "%s", "Hours:\n07PM:25:56\nDate:\n15/01/2003 19:25:56\n");
    REQUIRE(!memcmp(res, st.show(), 44));
}

TEST_CASE("Testing Template Stack") {
    char* res = new char[255];
    sprintf(res, "");
    StackT<Date> st1;
    Date d1(15,1,2003,19,25,56);
    Date d2(10,2,2034,14,35,16);
    Date d3(26,3,2021,5,16,27);
    st1.push(d1);
    st1.push(d2);
    st1.push(d3);

    StackT<Hours> st2;
    Hours h1(d1);
    Hours h2(d2);
    Hours h3(d3);
    st2.push(h1);
    st2.push(h2);
    st2.push(h3);

    StackT<Notes> st3;
    Notes n1(d1, "new note1");
    Notes n2(d2, "new note2");
    Notes n3(d3, "new note3");
    st3.push(n1);
    st3.push(n2);
    st3.push(n3);

    StackT<int> st4;
    st4.push(4532);
    st4.push(23);
    st4.push(643);

    strcat(res, st1.show());
    strcat(res, st2.show());
    strcat(res, st3.show());
    strcat(res, st4.show());

    char* tmp = new char[255];
    sprintf(tmp, "%s%s%s%s", "Date:\n26/03/2021 05:16:27\nDate:\n10/02/2034 14:35:16\nDate:\n15/01/2003 19:25:56\n", 
    "Hours:\n05AM:16:27\nHours:\n02PM:35:16\nHours:\n07PM:25:56\n", 
    "Notes:\n26/03/2021 05:16:27\nnew note3\nNotes:\n10/02/2034 14:35:16\nnew note2\nNotes:\n15/01/2003 19:25:56\nnew note1\n",
    "643\n23\n4532\n");

    
    REQUIRE(!memcmp(res, tmp, 255));
}
