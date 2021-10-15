#include "Hours.hpp"

class Notes : public Date {
public:
    Notes(Date &d, char *note) : Date(d) {
        this->note = new char[strlen(note)];
        this->setNote(note);
    } 

    char* getNote() {
        char *tmp = new char[19+strlen(this->note)+1];
        tmp = this->note;
        return tmp;
    }

    void setNote(char *note) {
        this->note = new char[19+strlen(note)+1];
        sprintf(this->note, "%.2d.%.2d.%.4d %.2d:%.2d:%.2d\n%s", this->getDay(), this->getMonth(), this->getYear(),
        this->getHour(), this->getMinute(), this->getSecond(), note);
    }

    ~Notes() { delete[] this->note; }

private:
    char *note;
};