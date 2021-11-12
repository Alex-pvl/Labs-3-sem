#pragma once
#include "Date.hpp"
#include "Hours.hpp"
#include "Notes.hpp"
#include "Methods.hpp"

int get_size(int x) {
    int val = x, s = 0;
    while (x != 0) {
        s++;
        x /= 10;
    }
    return s;
}

template <class T> 
class StackT {
public:
    StackT();
    void push(T data);
    T* pop();
    char* show();
    bool empty();
    int size();
    ~StackT();
private:
    
    class Node {
    public:
        Node();
        Node(T data);
        ~Node();
        friend class StackT;
    private:
        T *data;
        Node *next;
    };

    int _size;
    Node *root;
};

template <class T>
StackT<T>::StackT() {
    this->_size = 0;
    this->root = nullptr;    
}

template <class T>
void StackT<T>::push(T data) {
    Node *temp = new Node(data);
    temp->next = root;
    root = temp;
    _size++;    
}

template <>
void StackT<int>::push(int data) {
    Node *temp = new Node(data);
    temp->next = root;
    root = temp;
    _size++;    
}

template <class T>
T* StackT<T>::pop() {
    try {
        if(empty()) throw runtime_error("stack is empty.");
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Node *deleteNode = root;
    root = root->next;
    T *a = deleteNode->data;
    T *t = new T(*a);
    delete deleteNode;
    _size--;    
    return t;
}

template <class T>
char* StackT<T>::show() {
    Node *a = root;
    int s = 0;
    while(a != nullptr) {
        s += a->data->getSize() + 1;
        a = a->next;
    }
    char* res = new char[s + 1];
    sprintf(res, "");
    Node *ptr = root;
    while(ptr != nullptr) {
        strcat(res, ptr->data->toString());
        strcat(res, "\n");
        ptr = ptr->next;
    }
    return res;    
}

template<>
char* StackT<int>::show() {
    Node *a = root;
    int s = 0;
    while (a != nullptr) {
        s += get_size(*a->data);
        a = a->next;
    }
    char* res = new char[s+1];
    sprintf(res, "");
    int i = 0;
    Node *ptr = root;
    while (ptr != nullptr) {
        int temp = *ptr->data;
        int p = pow(10, get_size(temp)-1);
        for (; p > 0; p /= 10) {

            res[i++] = (temp / p) + '0'; 
            temp %= p;
        }
        res[i++] = '\n';
        ptr = ptr->next;
    }
    return res;
}

template <class T>
bool StackT<T>::empty() {
    return this->root == nullptr;
}

template <class T>
int StackT<T>::size() {
    return this->_size;
}

template <class T>
StackT<T>::~StackT() {
    while(!empty()) {
        pop();
    }
}

template <class T>
StackT<T>::Node::Node() {
    this->data = new T();
    this->next = nullptr;
}

template <class T>
StackT<T>::Node::Node(T data) {
    this->data = new T(data);
    this->next = nullptr;
}


template <class T>
StackT<T>::Node::~Node() {
    delete this->data;
}

