#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Account{
    private:
        string username;
        int pin;
        double balance;
        vector<string> accounts;

};
class SavingAccount : public Account{};
class CurrentAccount : public Account{};
class ATM{};
int main(){
    return 0;
}