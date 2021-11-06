#pragma once
#include "Date.hpp"
#include "Methods.hpp"
#include "Hours.hpp"
#include "Notes.hpp"

class Stack {
public:
    Stack();
    void push(Date data);
    void push(Hours data);
    void push(Notes data);
    void pop();
    char* show();
    bool empty();
    int size();
    ~Stack();
    
private:
    class Node {
    public:
        Node();
        Node(Date data);
        Node(Hours data);
        Node(Notes data);
        ~Node();
        friend class Stack;
    private:
        Date *data;
        Node *next;
    };

    int _size;
    Node *root;
};

Stack::Stack() {
    this->_size = 0;
    this->root = nullptr;
}

void Stack::push(Date data) {
    Node *temp = new Node(data);
    temp->next = root;
    root = temp;
    _size++;
}

void Stack::push(Hours data) {
    Node *temp = new Node(data);
    temp->next = root;
    root = temp;
    _size++;
}

void Stack::push(Notes data) {
    Node *temp = new Node(data);
    temp->next = root;
    root = temp;
    _size++;
}

void Stack::pop() {
    try
    {
        if(empty()) throw runtime_error("stack is empty.");
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Node *deleteNode = root;
    root = root->next;
    delete deleteNode;
    _size--;
}

char* Stack::show() {
    Node *a = root;
    int s = 0;
    while(a != NULL) {
        s += a->data->getSize() + 1;
        a = a->next;
    }
    char* res = new char[s + 1];
    sprintf(res, "");
    Node *ptr = root;
    while(ptr != NULL) {
        strcat(res, ptr->data->toString());
        strcat(res, "\n");
        ptr = ptr->next;
    }
    return res;
}

bool Stack::empty() {
    return this->root == nullptr;
}

int Stack::size() {
    return this->_size;
}

Stack::~Stack() {
    while(!empty()) {
        pop();
    }
}

Stack::Node::Node() {
    this->data = new Date();
    this->next = nullptr;
}

Stack::Node::Node(Date data) {
    this->data = new Date(data);
    this->next = nullptr;
}

Stack::Node::Node(Hours data) {
    this->data = new Hours(data);
    this->next = nullptr;
}

Stack::Node::Node(Notes data) {
    this->data = new Notes(data);
    this->next = nullptr;
}

Stack::Node::~Node() {
    delete this->data;
}
