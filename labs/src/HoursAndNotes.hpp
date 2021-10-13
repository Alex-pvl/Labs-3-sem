#include "Methods.hpp"

class Hours : public Date {
public:
    Hours(Date& d) {
        this->hours = new char[10];
        this->setHours(d);
    }

    Hours() {}

    char* getHours() { 
        char *t = new char[10];
        t = this->hours;
        return t;
    }

    void setHours(Date& d) {
        if (d.getHour() <= 12) {
            sprintf(this->hours, "%.2dAM:%.2d:%.2d", d.getHour(), d.getMinute(), d.getSecond());
        } else {
            sprintf(this->hours, "%.2dPM:%.2d:%.2d", d.getHour()-12, d.getMinute(), d.getSecond());
        }
    }

    ~Hours() { delete[] this->hours; }
private:
    char* hours;
};

class Notes : public Date {
public:
    Notes(Date &d, char *note) {
        this->note = new char[strlen(note)];
        this->setNote(d, note);
    } 

    char* getNote() {
        char *tmp = new char[19+strlen(this->note)+1];
        tmp = this->note;
        return tmp;
    }

    void setNote(Date &d, char *note) {
        this->note = new char[19+strlen(note)+1];
        sprintf(this->note, "%.2d.%.2d.%.4d %.2d:%.2d:%.2d\n%s", d.getDay(), d.getMonth(), d.getYear(),
        d.getHour(), d.getMinute(), d.getSecond(), note);
    }

    ~Notes() { delete[] this->note; }

private:
    char *note;
};