#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

#include "InvestmentCalculator.h"

using namespace std;

static void ClearInputLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static double GetDouble(const string& t_prompt, bool t_allowZero) {
    double value = 0.0;

    while (true) {
        cout << t_prompt;
        if (cin >> value) {
            if (t_allowZero) {
                if (value >= 0.0) return value;
            } else {
                if (value > 0.0) return value;
            }
            cout << "Please enter a valid value." << endl;
        } else {
            cout << "Invalid input. Please enter a number." << endl;
        }
        ClearInputLine();
    }
}

static int GetInt(const string& t_prompt) {
    int value = 0;

    while (true) {
        cout << t_prompt;
        if (cin >> value) {
            if (value > 0) return value;
            cout << "Please enter a value greater than 0." << endl;
        } else {
            cout << "Invalid input. Please enter a whole number." << endl;
        }
        ClearInputLine();
    }
}

static void ShowDataInputSummary(double t_initialInvestment,
                                 double t_monthlyDeposit,
                                 double t_annualInterestRate,
                                 int t_years) {
    cout << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: $" << fixed << setprecision(2) << t_initialInvestment << endl;
    cout << "Monthly Deposit:           $" << fixed << setprecision(2) << t_monthlyDeposit << endl;
    cout << "Annual Interest:           " << fixed << setprecision(2) << t_annualInterestRate << "%" << endl;
    cout << "Number of Years:           " << t_years << endl;
    cout << "Press any key to continue..." << endl;
}

int main() {
    try {
        char runAgain = 'Y';

        while (runAgain == 'Y' || runAgain == 'y') {
            cout << "********** Data Input **********" << endl;

            const double initialInvestment = GetDouble("Initial Investment Amount: ", false);
            const double monthlyDeposit = GetDouble("Monthly Deposit: ", true);
            const double annualInterestRate = GetDouble("Annual Interest (percent): ", false);
            const int years = GetInt("Number of Years: ");

            ShowDataInputSummary(initialInvestment, monthlyDeposit, annualInterestRate, years);

            // Wait for key press
            ClearInputLine();
            cin.get();

            cout << endl;

            InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, years);
            calculator.PrintReports();

            cout << endl << "Would you like to enter new values (Y/N)? ";
            cin >> runAgain;
            ClearInputLine();
            cout << endl;
        }

        cout << "Goodbye." << endl;
        return 0;
    }
    catch (const exception& e) {
        cout << "Program error: " << e.what() << endl;
        return 1;
    }
}
