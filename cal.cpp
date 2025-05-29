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
// cal.cpp
#include <iostream>
#include <iomanip>

using namespace std;

// Function to check if a year is leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get number of days in a month
int getDaysInMonth(int month, int year) {
    switch(month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

// Zeller’s Congruence algorithm to find day of week for 1st of month
int getStartDay(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int q = 1;
    int m = month;
    int k = year % 100;
    int j = year / 100;

    int h = (q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return (h + 6) % 7;  // Adjust to make Sunday=0
}

void printCalendar(int month, int year) {
    const string months[] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};
    const string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    cout << "\n  " << months[month - 1] << " " << year << "\n";
    for (const string& day : days) {
        cout << setw(4) << day;
    }
    cout << endl;

    int start = getStartDay(month, year);
    int daysInMonth = getDaysInMonth(month, year);

    // Print leading spaces
    for (int i = 0; i < start; ++i) {
        cout << setw(4) << " ";
    }

    // Print days
    for (int day = 1; day <= daysInMonth; ++day) {
        cout << setw(4) << day;
        if ((start + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << "\n";
}

int main() {
    int month, year;

    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year (e.g. 2025): ";
    cin >> year;

    if (month < 1 || month > 12 || year < 1) {
        cout << "Invalid input.\n";
        return 1;
    }

    printCalendar(month, year);
    return 0;
}}
