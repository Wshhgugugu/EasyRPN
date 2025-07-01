#ifndef STACK_H
#define STACK_H

// define the prototypes
class Stack {
protected:
    struct Node {
        double data;
        Node* next;
        Node(double d) : data(d), next(NULL) {}
    };

    Node* head;
    int rpnNum;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(double num);
    double pop();
    void display();
    int size();
};

class RPN : public Stack {
public:
    void add();
    void subtract();
    void multiply();
    void divide();
    void reciprocal();
    void sin();
    void cos();
    void tan();
    void SWAP();
    void power();
    void signChange();
    void instruction();
};

#endif
