#include <stdio.h>

int main() {
    double num1, num2;
    char operator;

    printf("Enter an expression (e.g. 4 + 5): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);

    switch(operator) {
        case '+':
            printf("Result: %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("Result: %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("Result: %.2lf\n", num1 * num2);
            break;
        case '/':
            if(num2 != 0)
                printf("Result: %.2lf\n", num1 / num2);
            else
                printf("Error: Division by zero!\n");
            break;
        default:
            printf("Error: Invalid operator.\n");
    }

    return 0;
import calendar
import tkinter as tk
from tkinter import ttk

def show_calendar():
    try:
        year = int(year_entry.get())
        month = int(month_entry.get())
        cal_text = calendar.month(year, month)
        output.delete("1.0", tk.END)
        output.insert(tk.END, cal_text)
    except:
        output.delete("1.0", tk.END)
        output.insert(tk.END, "Invalid input!")

# GUI Setup
root = tk.Tk()
root.title("Simple Calendar")

tk.Label(root, text="Year:").grid(row=0, column=0)
tk.Label(root, text="Month:").grid(row=1, column=0)

year_entry = ttk.Entry(root)
month_entry = ttk.Entry(root)
year_entry.grid(row=0, column=1)
month_entry.grid(row=1, column=1)

tk.Button(root, text="Show Calendar", command=show_calendar).grid(row=2, column=0, columnspan=2)

output = tk.Text(root, height=10, width=30)
output.grid(row=3, column=0, columnspan=2)

root.mainloop()}
