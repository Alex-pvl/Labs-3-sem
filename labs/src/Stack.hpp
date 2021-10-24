#pragma once
#include "Date.hpp"
#include "Methods.hpp"
#include "Hours.hpp"
#include "Notes.hpp"



// class Stack {
// public:
//     Stack() : _size(0), root(nullptr) {}

//     void push(Date *d) {
//         Node *newnode = new Node;
//         newnode->d = d;
//         newnode->next = root;
//         root = newnode;
//         _size++;
//     }

//     Date& top() {
//         if (empty()) {
//             throw length_error("stack is empty!");
//         }
//         return *(root->d);
//     }

//     void pop() {
//         if (empty()) {
//             throw length_error("stack is empty!");
//         }
//         Node *deletenode = root;
//         root = deletenode->next;
//         delete deletenode;
//         _size--;
//     }

//     bool empty() const {
//         return root == nullptr;
//     }

//     int size() {
//         return this->_size;
//     }

//     ~Stack() {
//         while (!empty()) {
//             pop();
//         }
//     }

// private:
//     struct Node {
//         Date *d;
//         Node *next;
//     };

//     int _size;
//     Node *root;
// };

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
        if (empty()) {
            throw runtime_error("stack is empty!");
        }
        return root;
    }

    void pop() {
        if (empty()) {
            throw runtime_error("stack is empty!");
        }
        Date *deleteDate = root;
        root = root->next;
        delete deleteDate;
        _size;
    }

    void show() {
        while (!empty()) {
            cout << top()->print() << endl;
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