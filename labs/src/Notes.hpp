#include "Methods.hpp"

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