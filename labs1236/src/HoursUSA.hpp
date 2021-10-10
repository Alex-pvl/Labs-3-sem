#include "Methods.hpp"

class Hours : public Date {
public:
    Hours(Date& d) {
        this->hours = new char[10];
        this->setHours(d);
    }

    char* getHours() { 
        return this->hours; 
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