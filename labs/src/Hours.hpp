#include "Methods.hpp"

class Hours : public Date {
public:
    Hours(Date& d) : Date(d) {
        this->hours = new char[10];
        this->setHours();
    }

    Hours() : Date() { this->setHours(); }

    char* getHours() { 
        char *t = new char[10];
        strcpy(t, this->hours);
        return t;
    }

    void setHours() {
        if (this->getHour() <= 12) {
            sprintf(this->hours, "%.2dAM:%.2d:%.2d", this->getHour(), this->getMinute(), this->getSecond());
        } else {
            sprintf(this->hours, "%.2dPM:%.2d:%.2d", this->getHour()-12, this->getMinute(), this->getSecond());
        }
    }

    ~Hours() { delete[] this->hours; }
private:
    char* hours;
};

