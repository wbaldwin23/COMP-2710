//  William Baldwin
//  wjb0031
//  project1_wjb0031.cpp
//  Project_1
//
//  Got help from Marco Gonzalez(for aligning),
//  my brother(for checking over my code), and stackoverflow.com(for aligning).
//

#include <iostream>
#include <iomanip>
#include <locale>

int main(int argc, const char * argv[]) {
    
    //Variables that are inputted by user.
    double loanAmount;
    double interestRate;
    double monthlyPay;
    int month = 1;
    
    //User inputs numbers for the program.
    std::cout << "Loan Amount: ";
    std::cin >> loanAmount;
    std::cout << "Interest Rate (% per year): ";
    std::cin >> interestRate;
    std::cout << "Monthly Payments: ";
    std::cin >> monthlyPay;
    
    //Setting a variable equal to loanAmount to use for equations in while loop.
    double balance = loanAmount;
    
    //Vaiables that will be used in the while loop and initial calculations.
    interestRate = interestRate/12;
    double interest = ((interestRate/100)* balance);
    double principal = monthlyPay - interest;
    double payment = monthlyPay;
    double interestPaid = 0;
    
    //Checks if the inputs are valid to calculate for paying off interest.
    if (interest > payment) {
        std::cout << "Error: Interest is higher than payment, adjust inputs.\n";
        balance = 0;
    }
    
    //Setting up the first row of information for the table.
    if (interest < payment) {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    std::cout << "0      $" << balance << "   N/A      N/A   N/A       N/A\n";
    }
    
    //The top of the table is coded here.
    if (interest < payment) {
    std::cout << "\n**********************************************************\n";
    std::cout << "\tAmortization Table\n";
    std::cout << "**********************************************************\n";
    std::cout << "Month  Balance  Payment    Rate  Interest  Principal\n";
    }
    
    //While loop that calculates and prints the info for the user.
    while (balance > 0) {
        
        //Calculations that keep producing numbers for the table to be printed.
        interest = ((interestRate/100)* balance);
        principal = (payment - interest);
        balance = balance - principal;
        payment = interest + principal;
        
        //An if statement to change the output of the last row so it does not go into negatives.
        if (balance < 0) {
            payment = payment + balance;
            principal = payment - interest;
            balance = 0;
        }
        
        
        //The output for each row in the program.
        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(2);
        std::cout << std::setw(2)<< std::left << month;
        std::cout <<  "     $" << std::setw(8)<< std::left<< balance;
        std::cout << " $" << std::setw(5)<< std::left << payment;
        std::cout << "    " << std::setw(4) << std::left << interestRate;
        std::cout << "  $" << std::setw(5) << std::left << interest;
        
        //An if statement to correct formatting if principal is negative.
        if (principal > 0) {
        std::cout << "    $" << principal << "\n";
        }
        else  {
        principal = principal * -1;
        std::cout << "   -$" << principal << "\n";
        }
        
        
        //An increment on months to use later.
        month++;
        interestPaid = interestPaid + interest;
   }
    if (interest < payment) {
    //Output for last line, that tells user amount of months and interest paid.
    std::cout << "********************************************************\n\n";
    std::cout << "It takes " << month - 1 << " months to pay off the loan.\n";
    std::cout << "Total interest paid is: $" << interestPaid << "\n\n";
    }
    return 0;
}
