#pragma once
#include "Date.hpp"

int Date::count = 0;

Date::Date() {
    this->date_time = new char[19];
    this->setDay(1);
    this->setMonth(1);
    this->setYear(1);
    this->setHour(0);
    this->setMinute(0);
    this->setSecond(0);
    count++;
}

Date::Date(int day, int mon, int year) {
    this->date_time = new char[19];
    this->setDay(day);
    this->setMonth(mon);
    this->setYear(year);
    this->setHour(0);
    this->setMinute(0);
    this->setSecond(0);
    count++;
}

Date::Date(int day, int mon, int year, int h, int m, int s) : Date::Date(day, mon, year) {
        this->date_time = new char[19];
        this->setHour(h);
        this->setMinute(m);
        this->setSecond(s);
        count++;
    }

Date::Date(const Date &d) {
        this->setDay(d.day);
        this->setMonth(d.mon);
        this->setYear(d.year);
        this->setHour(d.h);
        this->setMinute(d.m);
        this->setSecond(d.s);
        this->date_time = new char[19];
        strcpy(this->date_time, d.date_time);
        count++;
    }

int Date::getDay() { return this->day; }

int Date::getMonth() { return this->mon; }

int Date::getYear() { return this->year; }

int Date::getHour() { return this->h; }

int Date::getMinute() { return this->m; }

int Date::getSecond() { return this->s; }

int Date::getCount() { return count; }

char* Date::getDateTime() { 
        char* tmp = new char[19];
        tmp = this->date_time;
        return tmp;
    }

void Date::setDateTime() {
    sprintf(this->date_time, "%.2d/%.2d/%.4d %.2d:%.2d:%.2d", this->getDay(), this->getMonth(), this->getYear(),
    this->getHour(), this->getMinute(), this->getSecond());
}

char* Date::toString() { 
    char *res = new char[25];
    this->setDateTime();
    sprintf(res, "%s%s", "Date:\n", this->getDateTime()); 
    return res; 
}

void Date::setYear(int year) {
    try
    {
        if (year < 0) throw DateException("Invalid Date Format, check year");
        this->year = year;
    }
    catch(DateException& e)
    {
        cerr << e.what() << '\n';
    }
}
 
void Date::setMonth(int mon) {
    try
    {
        if (mon > 12 || mon < 0) throw DateException("Invalid Date Format, check month");
        this->mon = mon;
    }
    catch(DateException& e)
    {
        cerr << e.what() << '\n';
    }
}

void Date::setDay(int day) {
    try
    {
        if (day > 31 || day < 0) throw DateException("Invalid Date Format, check day");
        this->day = day;
    }
    catch(DateException& e)
    {
        cout<< e.what() << '\n';
    }
}

void Date::setHour(int h) {
    try
    {
        if (h > 23 || h < 0) throw DateException("Invalid Date Format, check hours");
        this->h = h;
    }
    catch(DateException& e)
    {
        cerr << e.what() << '\n';
    }
}

void Date::setMinute(int m) {
    try
    {
        if (m > 59 || m < 0) throw DateException("Invalid Date Format, check minutes");
        this->m = m;
    }
    catch(DateException& e)
    {
        cerr << e.what() << '\n';
    }
}

void Date::setSecond(int s) {
    try
    {
        if (s > 59 || s < 0) throw DateException("Invalid Date Format, check seconds");
        this->s = s;
    }
    catch(DateException& e)
    {
        cerr << e.what() << '\n';
    }
}

void Date::incYear() { this->setYear(this->getYear() + 1); }

void Date::incMonth() {
    if (this->getMonth() == 12) {
        this->incYear();
        this->setMonth(1);
    } else {
        this->setMonth(this->getMonth() + 1);
    }
}

void Date::incDay() {
    if ((this->getMonth() == 4 || this->getMonth() == 6 ||
    this->getMonth() == 9 || this->getMonth() == 11) && this->getDay() == 30) {
        this->incMonth();
        this->setDay(1);
    } else if (this->getMonth() == 2) {
        if (this->getYear() % 4 == 0) {
            if (this->getYear() % 100 == 0 && this->getYear() % 400 != 0) {
                if (this->getDay() == 28) {
                    this->incMonth();
                    this->setDay(1);
                } else {
                    this->setDay(this->getDay() + 1);
                }
            } else {
                if (this->getDay() == 29) {
                    this->incMonth();
                    this->setDay(1);
                } else {
                    this->setDay(this->getDay() + 1);
                }
            }
        } else if (this->getDay() == 28) {
            this->incMonth();
            this->setDay(1);
        } else {
            this->setDay(this->getDay() + 1);
        }
    } else if (this->getDay() == 31) {
        this->incMonth();
        this->setDay(1);
    } else {
        this->setDay(this->getDay() + 1);
    }
}

void Date::incHour() {
    if (this->getHour() == 23) {
        this->incDay();
        this->setHour(0);
    } else {
        this->setHour(this->getHour() + 1);
    }
}

void Date::incMinutes() {
    if (this->getMinute() == 59) {
        this->incHour();
        this->setMinute(0);
    } else {
        this->setMinute(this->getMinute() + 1);
    }
}

void Date::incSecond() {
    if (this->getSecond() == 59) {
        this->incMinutes();
        this->setSecond(0);
    } else {
        this->setSecond(this->getSecond() + 1);
    }
}

void Date::decYear() { this->setYear(this->getYear() - 1); }

void Date::decMonth() {
    if (this->getMonth() == 1) {
        this->decYear();
        this->setMonth(12); 
    } else {
        this->setMonth(this->getMonth() - 1);
    }
}

void Date::decDay() {
    if ((this->getMonth() == 5 || this->getMonth() == 7 ||
    this->getMonth() == 10 || this->getMonth() == 12) && this->getDay() == 1) {
        this->decMonth();
        this->setDay(30);
    } else if (this->getMonth() == 3) {
        if (this->getYear() % 4 == 0) {
            if (this->getYear() % 100 == 0 && this->getYear() % 400 != 0) {
                if (this->getDay() == 1) {
                    this->decMonth();
                    this->setDay(28);
                } else {
                    this->setDay(this->getDay() - 1);
                }
            } else {
                if (this->getDay() == 1) {
                    this->decMonth();
                    this->setDay(29);
                } else {
                    this->setDay(this->getDay() - 1);
                }
            }
        } else if (this->getDay() == 1) {
            this->decMonth();
            this->setDay(28);
        } else {
            this->setDay(this->getDay() - 1);
        }
    } else if (this->getDay() == 1) {
        this->decMonth();
        this->setDay(31);
    } else {
        this->setDay(this->getDay() - 1);
    }
} 

void Date::decHour() {
    if (this->getHour() == 0) {
        this->decDay();
        this->setHour(23);
    } else {
        this->setHour(this->getHour() - 1);
    }
}

void Date::decMinute() {
    if (this->getMinute() == 0) {
        this->decHour();
        this->setMinute(59);
    } else {
        this->setMinute(this->getMinute() - 1);
    }
}

void Date::decSecond() {
    if (this->getSecond() == 0) {
        this->decMinute();
        this->setSecond(59);
    } else {
        this->setSecond(this->getSecond() - 1);
    }
}

Date::operator char *() {
    this->setDateTime(); 
    return this->getDateTime();
}

Date& operator+(Date& d, int hours) {
    for (; hours > 0; hours--) d.incHour();
    return d;
} 

Date& operator-(Date& d, int hours) {
    for (; hours > 0; hours--) d.decHour();
    return d;
}

Date operator+(Date& d1, Date& d2) {
    return Date(d1.getDay()+d2.getDay(), d1.getMonth()+d2.getMonth(), d1.getYear()+d2.getYear(), d1.getHour()+d2.getHour(), d1.getMinute()+d2.getMinute(), d1.getSecond()+d2.getSecond());
}

Date operator-(Date& d1, Date& d2) {
    return Date(d1.getDay()-d2.getDay(), d1.getMonth()-d2.getMonth(), d1.getYear()-d2.getYear(), d1.getHour()-d2.getHour(), d1.getMinute()-d2.getMinute(), d1.getSecond()-d2.getSecond());
}



ofstream& writeToBin(ofstream& fout, const Date& d) {
    try
    {
        if (!fout.is_open()) throw DateException("Unadle to open this file\n");
        else {
            cout << "File opened\n";
            fout.write((char*)&d.day, sizeof(int));
            fout.write((char*)&d.mon, sizeof(int));
            fout.write((char*)&d.year, sizeof(int));
            fout.write((char*)&d.h, sizeof(int));
            fout.write((char*)&d.m, sizeof(int));
            fout.write((char*)&d.s, sizeof(int));
            
            fout.close();
        }
    }
    catch(DateException& e)
    {
        cerr << e.what() << '\n';
    }
    return fout;
}

ifstream& readFromBin(ifstream& fin, Date& d) {
    try
    {
        if (!fin.is_open()) throw DateException("Unable to open this file\n");
        else {
            cout << "File opened\n";
            fin.read((char*)&d.day, sizeof(int));
            fin.read((char*)&d.mon, sizeof(int));
            fin.read((char*)&d.year, sizeof(int));
            fin.read((char*)&d.h, sizeof(int));
            fin.read((char*)&d.m, sizeof(int));
            fin.read((char*)&d.s, sizeof(int));
            d.setDateTime();
            fin.close();
        }
    }
    catch(DateException& e)
    {
        cerr << e.what() << '\n';
    }
    return fin;
}

ostream& operator<<(ostream& os, Date& d) {  
    d.setDateTime();
    os << d.getDateTime();
    return os;
}

istream& operator>>(istream& is, Date& d) {
    int day, mon, year, h, m, s;
    char date[10], time[8];
    is >> date;
    if (date[0] == 0) {
        day = date[1] - '0';
    } else {
        day = 10 * (date[0]-'0') + date[1] - '0';
    }
    if (date[3] == 0) {
        mon = date[4] - '0';
    } else {
        mon = 10 * (date[3] - '0') + date[4] - '0';
    }
    if (date[6] == 0) {
        if (date[7] == 0) {
            if (date[8] == 0) {
                year = date[9] - '0';
            } else {
                year = 10 * (date[8] - '0') + date[9] - '0';
            }
        } else {
            year = 100 * (date[7] - '0') + 10 * (date[8] - '0') + date[9] - '0';
        }
    } else {
        year = 1000 * (date[6] - '0') + 100 * (date[7] - '0') + 10 * (date[8] - '0') + date[9] - '0';
    }
    d.setDay(day); d.setMonth(mon); d.setYear(year);
    is >> time;
    if (time[0] == 0) {
        h = time[1] - '0';
    } else {
        h = 10 * (time[0] - '0') + time[1] - '0';
    }
    if (time[3] == 0) {
        m = time[4] - '0';
    } else {
        m = 10 * (time[3] - '0') + time[4] - '0';
    }
    if (time[6] == 0) {
        s = time[7] - '0';
    } else {
        s = 10 * (time[6] - '0') + time[7] - '0';
    }
    d.setHour(h); d.setMinute(m); d.setSecond(s);
    d.setDateTime();
    return is;
}

Date::~Date() {
    //delete[] this->date_time;    
    count--;
}

Date& Date::operator=(const Date& d) {
    day = d.day;
    mon = d.mon;
    year = d.year;
    h = d.h;
    m = d.m;
    s = d.s;
    this->date_time = new char[19];
    strcpy(this->date_time, d.date_time);
    return *this;
}

int Date::getSize() {
    return strlen(this->toString());
}

bool operator==(Date& d1, Date& d2) {
    return (d1.getDateTime() == d2.getDateTime());
}