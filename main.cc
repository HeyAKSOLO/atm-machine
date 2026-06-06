#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Account{
    private:
        vector<SavingAccount> savingsAccounts;
        vector<CurrentAccount> currentAccounts;

    protected:
        string username;
        string pin;
        double balance;

};
class SavingAccount : public Account{};
class CurrentAccount : public Account{};
class ATM{};
int main(){
    return 0;
}