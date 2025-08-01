#ifndef MYSTACK_H
#define MYSTACK_H

#include "Stack.h"

class MyStack : public Stack {
private:
    struct Node {
        double data;
        Node* next;
        Node(double val, Node* nxt = nullptr) : data(val), next(nxt) {}
    };

    Node* head;

public:
    MyStack();
    ~MyStack();

    void clear() override;
    bool is_empty() const override;
    void push(double item) override;
    double pop() override;
    double top() const override;
};

#endif
