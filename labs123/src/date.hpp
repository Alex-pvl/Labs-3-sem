#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

class Date {

public:
    Date() {
        count++;
    }

    Date(int day, int mon, int year) {
        this->date_time = new char[19];
        this->setDay(day);
        this->setMonth(mon);
        this->setYear(year);
        this->setHour(0);
        this->setMinute(0);
        this->setSecond(0);
        count++;
    }

    Date(int day, int mon, int year, int h, int m, int s) {
        this->date_time = new char[19];
        this->setDay(day);
        this->setMonth(mon);
        this->setYear(year);
        this->setHour(h);
        this->setMinute(m);
        this->setSecond(s);
        count++;
    }

    Date(const Date &d) {
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

    int getYear() { return this->year; }

    int getMonth() { return this->mon; }

    int getDay() { return this->day; }

    int getHour() { return this->h; }

    int getMinute() { return this->m; }

    int getSecond() { return this->s; }
    
    static int getCount() { return count; }
    
    char* getDateTime() { 
        char* tmp = new char[19];
        tmp = this->date_time;
        return tmp;
    }

    void setDateTime() {
        sprintf(this->date_time, "%.2d.%.2d.%.4d %.2d:%.2d:%.2d", this->getDay(), this->getMonth(), this->getYear(),
        this->getHour(), this->getMinute(), this->getSecond());
    }

    char* toString() { return this->getDateTime(); }

    void setYear(int year) { this->year = year; }

    void setMonth(int mon) { this->mon = mon; }

    void setDay(int day) { this->day = day; }

    void setHour(int h) { this->h = h; }
 
    void setMinute(int m) { this->m = m; }

    void setSecond(int s) { this->s = s; }

    // кол-во разрядов числа
    int getSize(int n) {
        int size = 0;
        for (int i = n; i > 0; i /= 10) {
            size++;
        }
        return size;
    }

    void incYear() { this->setYear(this->getYear() + 1); }

    void incMonth() {
        if (this->getMonth() == 12) {
            this->incYear();
            this->setMonth(1);
        } else {
            this->setMonth(this->getMonth() + 1);
        }
    }

    void incDay() {
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

    void incHour() {
        if (this->getHour() == 23) {
            this->incDay();
            this->setHour(0);
        } else {
            this->setHour(this->getHour() + 1);
        }
    }

    void incMinutes() {
        if (this->getMinute() == 59) {
            this->incHour();
            this->setMinute(0);
        } else {
            this->setMinute(this->getMinute() + 1);
        }
    }

    void incSecond() {
        if (this->getSecond() == 59) {
            this->incMinutes();
            this->setSecond(0);
        } else {
            this->setSecond(this->getSecond() + 1);
        }
    }

    void decYear() { this->setYear(this->getYear() - 1); }

    void decMonth() {
        if (this->getMonth() == 1) {
            this->decYear();
            this->setMonth(12); 
        } else {
            this->setMonth(this->getMonth() - 1);
        }
    }

    void decDay() {
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

    void decHour() {
        if (this->getHour() == 0) {
            this->decDay();
            this->setHour(23);
        } else {
            this->setHour(this->getHour() - 1);
        }
    }

    void decMinute() {
        if (this->getMinute() == 0) {
            this->decHour();
            this->setMinute(59);
        } else {
            this->setMinute(this->getMinute() - 1);
        }
    }

    void decSecond() {
        if (this->getSecond() == 0) {
            this->decMinute();
            this->setSecond(59);
        } else {
            this->setSecond(this->getSecond() - 1);
        }
    }

    operator char*() {
        this->setDateTime(); 
        return this->getDateTime();
    }

    friend Date& operator+(Date& d ,int hours);

    friend Date& operator-(Date& d ,int hours);

    friend Date operator+(Date& d1, Date& d2); 

    friend Date operator-(Date& d1, Date& d2);

    Date& operator=(const Date& d) {
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

    // запись
    friend ostream& operator<<(ostream& os, Date& d);
    // чтение
    friend istream& operator>>(istream& is, Date& d);    

    ~Date() {
        delete[] this->date_time;
        count--;
    }

private:
    int year;
    int mon;
    int day;
    int h;
    int m;
    int s;
    char* date_time;
    static int count;
};

int Date::count = 0;

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

ostream& operator<<(ostream& os, Date& d) {
    os << d.getCount() << ") " << setfill('0') << setw(2) << d.getDay() << "." << setfill('0') << setw(2) << d.getMonth()
     << "." << setfill('0') << setw(4) << d.getYear() << " " << setfill('0') << setw(2) << d.getHour() << ":" 
     << setfill('0') << setw(2) << d.getMinute() << ":" << setfill('0') << setw(2) << d.getSecond() << "\n";
    return os; 
}

istream& operator>>(istream& is, Date& d) {
    is >> d.day >> d.mon >> d.year >> d.h >> d.m >> d.s;
    return is;
}

const char *fileName_txt = "text.txt";
const char *fileName_bin = "binary.bin";
