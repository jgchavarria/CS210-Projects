#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

#include <string>

class InvestmentCalculator {
public:
    InvestmentCalculator(double t_initialInvestment,
                         double t_monthlyDeposit,
                         double t_annualInterestRatePercent,
                         int t_numberOfYears);

    void PrintReports() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRatePercent; // ex: 5 means 5%
    int m_numberOfYears;

    void PrintSingleReport(double t_monthlyDepositForThisReport,
                           const std::string& t_title) const;

    static double MonthlyInterest(double t_balance,
                                  double t_monthlyDeposit,
                                  double t_annualInterestRatePercent);
};

#endif
