#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Enter an expression (e.g. 10 + 5): ";
    cin >> num1 >> op >> num2;

    switch(op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        default:
            cout << "Error: Invalid operator" << endl;
    }

    return 0;
}
