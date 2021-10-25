#pragma once
#include "Date.hpp"
#include "Methods.hpp"
#include "Hours.hpp"
#include "Notes.hpp"

class stack {
public:
    stack() : _size(0), root(nullptr) {}

    void push(Date& d) {
        Date* temp = nullptr;
        temp = (&d)->copy();
        temp->next = root;
        root = temp;
        _size++;
    }

    Date* top() {
        try
        {
            if (empty()) throw runtime_error("stack is empty!");
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
        }
        return root;
    }

    void pop() {
        try
        {
            if (empty()) throw runtime_error("stack is empty!");
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
        }
        Date *deleteDate = root;
        root = root->next;
        delete deleteDate;
        _size;
    }

    void show() {
        while (!empty()) {
            top()->print();
            cout << endl;
            pop();
        }
    }

    int size() {
        return this->_size;
    }

    bool empty() {
        return this->root == nullptr;
    }

    ~stack() {
        while(!empty()) {
            pop();
        }
    }
private:
    int _size;
    Date *root;
};