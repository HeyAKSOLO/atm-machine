#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Account{
    
    protected:
    string username;
    string pin;
    double balance;
    
};
class SavingAccount : public Account{};
class CurrentAccount : public Account{};
class ATM{
    private:
    vector<SavingAccount> savingsAccounts;
    vector<CurrentAccount> currentAccounts;
    
};
int main(){
    return 0;
}