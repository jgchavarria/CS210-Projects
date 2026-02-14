#include "InvestmentCalculator.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

InvestmentCalculator::InvestmentCalculator(double t_initialInvestment,
                                           double t_monthlyDeposit,
                                           double t_annualInterestRatePercent,
                                           int t_numberOfYears)
    : m_initialInvestment(t_initialInvestment),
      m_monthlyDeposit(t_monthlyDeposit),
      m_annualInterestRatePercent(t_annualInterestRatePercent),
      m_numberOfYears(t_numberOfYears) {

    // Basic validation (secure/best-practice)
    if (m_initialInvestment <= 0.0) {
        throw invalid_argument("Initial investment must be greater than 0.");
    }
    if (m_monthlyDeposit < 0.0) {
        throw invalid_argument("Monthly deposit cannot be negative.");
    }
    if (m_annualInterestRatePercent <= 0.0) {
        throw invalid_argument("Annual interest rate must be greater than 0.");
    }
    if (m_numberOfYears <= 0) {
        throw invalid_argument("Number of years must be greater than 0.");
    }
}

double InvestmentCalculator::MonthlyInterest(double t_balance,
                                             double t_monthlyDeposit,
                                             double t_annualInterestRatePercent) {
    // (balance + monthlyDeposit) * ((rate/100)/12)
    const double monthlyRate = (t_annualInterestRatePercent / 100.0) / 12.0;
    return (t_balance + t_monthlyDeposit) * monthlyRate;
}

void InvestmentCalculator::PrintSingleReport(double t_monthlyDepositForThisReport,
                                             const string& t_title) const {
    cout << t_title << endl;
    cout << string(70, '=') << endl;

    cout << left << setw(10) << "Year"
         << right << setw(22) << "Year End Balance"
         << right << setw(30) << "Year End Earned Interest" << endl;

    cout << string(70, '-') << endl;

    double balance = m_initialInvestment;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            const double interest = MonthlyInterest(balance,
                                                    t_monthlyDepositForThisReport,
                                                    m_annualInterestRatePercent);
            yearlyInterest += interest;
            balance += t_monthlyDepositForThisReport + interest;
        }

        cout << left << setw(10) << year
             << right << setw(22) << fixed << setprecision(2) << balance
             << right << setw(30) << fixed << setprecision(2) << yearlyInterest
             << endl;
    }
}

void InvestmentCalculator::PrintReports() const {
    PrintSingleReport(0.0, "Balance and Interest Without Additional Monthly Deposits");
    cout << endl;
    PrintSingleReport(m_monthlyDeposit, "Balance and Interest With Additional Monthly Deposits");
}
