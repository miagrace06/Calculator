#include "MyStack.h"
#include <stdexcept>

MyStack::MyStack() : head(nullptr) {}

MyStack::~MyStack() {
    while (!isEmpty()) {
        pop();
    }
}

void MyStack::push(double value) {
    head = new Node(value, head);
}

double MyStack::pop() {
    if (isEmpty()) throw std::runtime_error("Stack underflow.");
    Node* oldHead = head;
    double value = head->data;
    head = head->next;
    delete oldHead;
    return value;
}

double MyStack::top() const {
    if (isEmpty()) throw std::runtime_error("Stack underflow.");
    return head->data;
}

bool MyStack::isEmpty() const {
    return head == nullptr;
}
