#include "HoursAndNotes.hpp"

class List : public Date {
public:
    List() {}

    List(Date& o) {}

    ~List() {}

    List* addElem(List* l, Date& d) {
        List *q = new List;
        q->o = d;
        q->next = l;
        l = q;
        return l;
    }

    List* deleteElem(List* l) {
        
    }

private:
    List *next;
    Date o;
};