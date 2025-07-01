#include "Stack.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor
Stack::Stack() {
    head = NULL;
    rpnNum = 0;
}

// Check if stack is empty
bool Stack::isEmpty() {
    return rpnNum == 0;
}

// Check if stack is full
bool Stack::isFull() {
    return rpnNum == 19;
}

// Push value to the stack
void Stack::push(double num) {
    if (isFull()) {
        cout << "This stack is full, new number ignored..." << endl;
        return;
    }
    Node* current = new Node(num);
    current->next = head;
    head = current;
    rpnNum++;
}

// Pop value from the stack
double Stack::pop() {
    if (isEmpty()) {
        cout << "The stack is empty, no calculations can be made..." << endl;
        return 1;
    }
    Node* temp = head;
    double element = temp->data;
    head = head->next;
    delete temp;
    rpnNum--;
    return element;
}

// Display all values
void Stack::display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Return size
int Stack::size() {
    return rpnNum;
}

// ------------------- RPN functions -------------------

void RPN::add() {
    if (size() < 2) 
      return;
    double a = pop(), b = pop();
    push(b + a);
}

void RPN::subtract() {
    if (size() < 2) 
      return;
    double a = pop(), b = pop();
    push(b - a);
}

void RPN::multiply() {
    if (size() < 2) 
      return;
    double a = pop(), b = pop();
    push(b * a);
}

void RPN::divide() {
    if (size() < 2) 
      return;
    double a = pop(), b = pop();
    if (a == 0) {
        cout << "0 cannot be the denominator..." << endl;
        push(b); push(a);
        return;
    }
    push(b / a);
}

void RPN::reciprocal() {
    if (isEmpty()) 
      return;
    double a = pop();
    if (a == 0) {
        cout << "0 cannot be a denominator..." << endl;
        push(a);
        return;
    }
    push(1 / a);
}

void RPN::sin() {
    if (isEmpty()) 
      return;
    double a = pop();
    push(std::sin(a));
}

void RPN::cos() {
    if (isEmpty()) 
      return;
    double a = pop();
    push(std::cos(a));
}

void RPN::tan() {
    if (isEmpty()) 
      return;
    double a = pop();
    push(std::tan(a));
}

void RPN::SWAP() {
    if (size() < 2) 
      return;
    double a = pop(), b = pop();
    push(a); push(b);
}

void RPN::power() {
    if (size() < 2) 
      return;
    double a = pop(), b = pop();
    push(std::pow(b, a));
}

void RPN::signChange() {
    if (isEmpty()) 
      return;
    double a = pop();
    push(-a);
}

void RPN::instruction() {
    cout << "------------------ INSTRUCTIONS ------------------" << endl;
    cout << "+     : Add the top two numbers" << endl;
    cout << "-     : Subtract the second top number from the top" << endl;
    cout << "*     : Multiply the top two numbers" << endl;
    cout << "/     : Divide the second top number by the top" << endl;
    cout << "^     : Raise the second top number to the power of the top" << endl;
    cout << "1/x   : Reciprocal of the top number (1 ÷ top)" << endl;
    cout << "+/-   : Change the sign of the top number" << endl;
    cout << "sin   : Sine of the top number (in radians)" << endl;
    cout << "cos   : Cosine of the top number (in radians)" << endl;
    cout << "tan   : Tangent of the top number (in radians)" << endl;
    cout << "POP   : Remove the top number from the stack" << endl;
    cout << "SWAP  : Swap the top two numbers on the stack" << endl;
    cout << "c     : Clear the top number (same as POP)" << endl;
    cout << "e     : Exit the program" << endl;
    cout << "i     : Show this instruction manual" << endl;
    cout << "--------------------------------------------------" << endl;
}
