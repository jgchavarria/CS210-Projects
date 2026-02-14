/*
 * Calculator.cpp
 *
 * Date: 01-17-26
 * Author: Jorge Chavarria
 *
 */

#include <iostream>
using namespace std;

int main()   // FIX: main must return int, not void
{
    double num1, num2;     // FIX: Use double to allow decimals
    char operation;        // Stores +, -, *, or /
    char answer = 'Y';     // FIX: char uses single quotes and needed a semicolon

    // Loop continues while user wants to keep going
    while (answer == 'Y' || answer == 'y')
    {
        cout << "Enter an expression (example: 2 + 2): " << endl;

        // FIX: Read input in the correct order
        cin >> num1 >> operation >> num2;

        // FIX: Removed semicolons after if statements
        if (operation == '+')
        {
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        }
        else if (operation == '-')
        {
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
        }
        else if (operation == '*')
        {
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        }
        else if (operation == '/')
        {
            // FIX: Prevent division by zero
            if (num2 == 0)
            {
                cout << "Error: Cannot divide by zero." << endl;
            }
            else
            {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            }
        }
        else
        {
            // FIX: Handle invalid operators
            cout << "Invalid operator. Please use +, -, *, or /." << endl;
        }

        cout << "Do you want to evaluate another expression? (Y/N): ";
        cin >> answer;
    }

    // Required message when program ends
    cout << "Program Finished." << endl;

    return 0;   // FIX: End program properly
}
