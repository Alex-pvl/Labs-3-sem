#include "Methods.hpp"

class Hours : public Date {
public:
    Hours(Date& d) {
        this->setHours(d);
    }

    char* getHours() { return this->hours; }

    void setHours(Date& d) {
        
    }

    ~Hours() { delete[] this->hours; }
private:
    char* hours;
};