#include <iostream>
#include <iomanip>
#include <cmath>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

// define the clear screen function
void clearscreen() {
    cout << "\033[2J\033[1;1H";
}

//define a function that shows the graphical interface
void displayButtons() {
    // Display calculator button
    cout << "╔══════════════════════════════════╗" << endl;
    cout << "║ [+] [-] [*] [/] [^] [1/x] [+/-]  ║" << endl;
    cout << "║ [sin] [cos] [tan] [POP] [SWAP]   ║" << endl;
    cout << "║ [c] Clear Top   [e] Exit         ║" << endl;
    cout << "║ Input number or command          ║" << endl;
    cout << "╚══════════════════════════════════╝" << endl;
}


int main() {
    // Create calculator object and input string
    RPN calculator;
    string input;
    int number;

    // Main calculator loop
    while (1) {
        // Clear screen and display UI
        clearscreen();
        cout << "╔══════════════════════════════════╗" << endl << "║" << setw(24) << "RPN CALCULATOR" << setw(13) << "║" << endl;
        displayButtons();
        cout << "Enter i for instructions" << endl;
        cout << "Number of numbers in the stack: " << calculator.size() << endl;
        cout << "The numbers in the stack are: ";
        calculator.display();

        // Get user input
        cin >> input;

        // Handle operations based on user input
        if (input == "+") {
            calculator.add();
            clearscreen();
        } else if (input == "-") {
            calculator.subtract();
            clearscreen();
        } else if (input == "*") {
            calculator.multiply();
            clearscreen();
        } else if (input == "/") {
            calculator.divide();
            clearscreen();
        } else if (input == "e") {
            // exit program
            break; 
        } else if (input == "c") {
            // clear top
            calculator.pop(); 
            clearscreen();
        } else if (input == "i") {
            // show instructions
            calculator.instruction(); 
        } else if (input == "1/x") {
            calculator.reciprocal();
            clearscreen();
        } else if (input == "sin") {
            calculator.sin();
            cout << "Answer calculated by radians, be careful of the results..." << endl;
            clearscreen();
        } else if (input == "cos") {
            calculator.cos();
            cout << "Answer calculated by radians, be careful of the results..." << endl;
            clearscreen();
        } else if (input == "tan") {
            calculator.tan();
            cout << "Answer calculated by radians, be careful of the results..." << endl;
            clearscreen();
        } else if (input == "SWAP" || input == "swap") {
            calculator.SWAP();
            clearscreen();
        } else if (input == "^") {
            calculator.power();
            clearscreen();
        } else if (input == "+/-") {
            calculator.signChange();
            clearscreen();
        } else {
            // Assume it's a number and push to stack
            // Convert to numbers
            calculator.push(stod(input));
            clearscreen();
        }
    }
}
