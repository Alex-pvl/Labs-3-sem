#pragma once
#include "Methods.hpp"

class Notes : public Date {
public:
    Notes() : Date() {
        this->note = new char[1];
    }

    Notes(Date &d, char *note) : Date(d) {
        this->note = new char[strlen(note)];
        this->setNote(note);
    } 

    char* getNote() {
        char *tmp = new char[19+strlen(this->note)+1];
        strcpy(tmp, this->note);
        return tmp;
    }

    void setNote(char *note) {
        this->note = new char[19+strlen(note)+1];
        sprintf(this->note, "%.2d/%.2d/%.4d %.2d:%.2d:%.2d\n%s", this->getDay(), this->getMonth(), this->getYear(),
        this->getHour(), this->getMinute(), this->getSecond(), note);
    }

    char* toString() { 
        char *res = new char[7+strlen(this->note)];
        sprintf(res, "%s%s", "Notes:\n", this->getNote()); 
        return res; 
    }

    ~Notes() { delete[] this->note; }

    int getSize() {
        return strlen(this->toString());
    }

private:
    char *note;
};
