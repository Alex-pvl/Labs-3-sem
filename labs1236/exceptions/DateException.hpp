#include <iostream>
using namespace std;

class DateException : public exception {
public:
    DateException(const char* msg) {
        this->msg = msg;
    }

    const char* what() {
        return this->msg;
    }

private:
    const char* msg;
};