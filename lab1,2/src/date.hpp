#include <iostream>
#include <cmath>
using namespace std;

class Date {

private:
    int year;
    int mon;
    int day;
    int h;
    int m;
    int s;
    char* date_time;
    static int count;

public:
    int getYear() { return this->year; }

    int getMonth() { return this->mon; }

    int getDay() { return this->day; }

    int getHour() { return this->h; }

    int getMinute() { return this->m; }

    int getSecond() { return this->s; }

    char* getDateTime() { return this->date_time; }

    static int getCount() { return count; }

    void setYear(int year) { this->year = year; }

    void setMonth(int mon) { this->mon = mon; }

    void setDay(int day) { this->day = day; }

    void setHour(int h) { this->h = h; }
 
    void setMinute(int m) { this->m = m; }

    void setSecond(int s) { this->s = s; }

    int getSize(int n) {
        int size = 0;
        for (int i = n; i > 0; i /= 10) {
            size++;
        }
        return size;
    }

    void incYear() {
        this->setYear(this->getYear() + 1);
    }

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

    void decYear() {
        this->setYear(this->getYear() - 1);
    }

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

    int i = 0;
    char* setDateTime() {
        int year = this->year, mon = this->mon, day = this->day, h = this->h, m = this->m, s = this->s;
        int year_s = getSize(year), year_p = pow(10, year_s-1); 
        int mon_s = getSize(mon), mon_p = pow(10, mon_s-1);
        int day_s = getSize(day), day_p = pow(10, day_s-1);
        int h_s = getSize(h), h_p = pow(10, h_s-1);
        int m_s = getSize(m), m_p = pow(10, m_s-1);
        int s_s = getSize(s), s_p = pow(10, s_s-1);
        
        if (day == 0) {
            date_time[i++] = (char) '0';
            date_time[i++] = (char) '0';
        } 
        for (int dy = day; day_p > 0; day_p /= 10) {
            if (day / 10 == 0) {
                date_time[i++] = '0';
            }
            date_time[i++] = (char) (dy / day_p + '0');
            dy %= day_p;
        }
        date_time[i++] = '.';
        if (mon == 0) {
            date_time[i++] = (char) '0';
            date_time[i++] = (char) '0';
        } 
        for (int mn = mon; mon_p > 0; mon_p /= 10) {
            if (mon / 10 == 0) {
                date_time[i++] = '0';
            } 
            date_time[i++] = (char) (mn / mon_p + '0');
            mn %= mon_p;
        }
        date_time[i++] = '.';
        if (year == 0) {
            date_time[i++] = (char) '0';
            date_time[i++] = (char) '0';
            date_time[i++] = (char) '0';
            date_time[i++] = (char) '0';
        } 
        for (int yr = year; year_p > 0; year_p /= 10) {
            date_time[i++] = (char) (yr / year_p + '0');
            yr %= year_p;
        }
        date_time[i++] = ' ';
        if (h == 0) {
            date_time[i++] = (char) '0';
            date_time[i++] = (char) '0';
        } 
        for (int hour = h; h_p > 0; h_p /= 10) {
            if (h / 10 == 0) {
                date_time[i++] = (char) '0';
            } 
            date_time[i++] = (char) (hour / h_p + '0');
            hour %= h_p;
        }
        date_time[i++] = ':';
        if (m == 0) {
            date_time[i++] = (char) '0';
            date_time[i++] = (char) '0';
        } 
        for (int min = m; m_p > 0; m_p /= 10) {
            if (m / 10 == 0) {
                date_time[i++] = (char) '0';
            } 
            date_time[i++] = (char) (min / m_p + '0');
            min %= m_p;
        }
        date_time[i++] = ':';
        if (s == 0) {
            date_time[i++] = (char) '0';
            date_time[i] = (char) '0';
        } 
        for (int sec = s; s_p > 0; s_p /= 10) {
            if (s / 10 == 0) {
                date_time[i++] = (char) '0';
            } 
            date_time[i] = (char) (sec / s_p + '0');
            sec %= s_p;
        }
        return date_time;
    }
    
    void toString() {
        this->setDateTime();
        for (int j = 0; j <= i; j++) {
            cout << this->getDateTime()[j];
        }
        cout << endl;
    }

    //lr2
    friend int addition(Date d1, Date d2, char c);

    friend int subtraction(Date d1, Date d2, char c);

    operator char*() {
        this->setDateTime(); 
        return date_time;
    }

    friend Date operator+(Date d1, Date d2); 

    friend Date operator-(Date d1, Date d2);

    Date& operator=(const Date& d) {
        day = d.day;
        mon = d.mon;
        year = d.year;
        h = d.h;
        m = d.m;
        s = d.s;
        date_time = d.date_time;
        count++;
        return *this;
    }

    Date() {
        count++;
    }

    Date(int day, int mon, int year) {
        this->date_time = new char[i];
        this->setDay(day);
        this->setMonth(mon);
        this->setYear(year);
        this->setHour(0);
        this->setMinute(0);
        this->setSecond(0);
        count++;
    }

    Date(int day, int mon, int year, int h, int m, int s) {
        this->date_time = new char[i];
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
        this->date_time = d.date_time;
        count++;
    }

    ~Date() {
        delete[] date_time;
        count--;
    }
};

int Date::count = 0;

int addition(Date d1, Date d2, char c) {
    switch (c) {
        case 'h':
            return d1.getHour() + d2.getHour();
            break;
        case 'd':
            return d1.getDay() + d2.getDay();
            break;
        default: return -1;
    }
}

int subtraction(Date d1, Date d2, char c) {
    switch (c) {
        case 'h':
            return d1.getHour() - d2.getHour();
            break;
        case 'd':
            return d1.getDay() - d2.getDay();
            break;
        default: return -1;
    }
}

Date operator+(Date d1, Date d2) {
    return Date(d1.getDay()+d2.getDay(), d1.getMonth()+d2.getMonth(), d1.getYear()+d2.getYear(), d1.getHour()+d2.getHour(), d1.getMinute()+d2.getMinute(), d1.getSecond()+d2.getSecond());
}

Date operator-(Date d1, Date d2) {
    return Date(d1.getDay()-d2.getDay(), d1.getMonth()-d2.getMonth(), d1.getYear()-d2.getYear(), d1.getHour()-d2.getHour(), d1.getMinute()-d2.getMinute(), d1.getSecond()-d2.getSecond());
}