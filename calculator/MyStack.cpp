#include "MyStack.h"
#include <stdexcept>

MyStack::MyStack() : head(nullptr) {}

MyStack::~MyStack() {
    clear();
}

void MyStack::clear() {
    while (!is_empty()) {
        pop();
    }
}

bool MyStack::is_empty() const {
    return head == nullptr;
}

void MyStack::push(double item) {
    head = new Node(item, head);
}

double MyStack::pop() {
    if (is_empty()) throw std::underflow_error("Stack underflow.");
    Node* oldHead = head;
    double value = head->data;
    head = head->next;
    delete oldHead;
    return value;
}

double MyStack::top() const {
    if (is_empty()) throw std::underflow_error("Stack underflow.");
    return head->data;
}
