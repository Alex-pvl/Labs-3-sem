#pragma once
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include "../exceptions/DateException.hpp"

class Date {

public:
    Date();

    Date(int day, int mon, int year);

    Date(int day, int mon, int year, int h, int m, int s);

    Date(const Date &d);
    
    ~Date();
    
    int getYear();

    int getMonth();

    int getDay();

    int getHour();

    int getMinute();

    int getSecond();
    
    static int getCount();
    
    char* getDateTime();

    void setDateTime();

    virtual char* toString();

    void setYear(int year);

    void setMonth(int mon);

    void setDay(int day);

    void setHour(int h);
 
    void setMinute(int m);

    void setSecond(int s);

    void incYear();

    void incMonth();

    void incDay();

    void incHour();

    void incMinutes();

    void incSecond();

    void decYear();

    void decMonth();

    void decDay();

    void decHour();

    void decMinute();

    void decSecond();

    operator char*();

    friend Date& operator+(Date& d ,int hours);

    friend Date& operator-(Date& d ,int hours);

    friend Date operator+(Date& d1, Date& d2); 

    friend Date operator-(Date& d1, Date& d2);

    Date& operator=(const Date& d);

    friend ostream& operator<<(ostream& os, Date& d);

    friend istream& operator>>(istream& is, Date& d);

    friend ofstream& writeToBin(ofstream& fout, const Date& d);

    friend ifstream& readFromBin(ifstream& fin, Date& d);

    virtual int getSize();

    friend bool operator==(Date& d1, Date& d2);

private:
    int day;
    int mon;
    int year;
    int h;
    int m;
    int s;
    char* date_time;
    static int count;  
};
