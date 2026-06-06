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

    public:
        Account(string acc_username, string acc_pin, double acc_balance) : username(acc_username), pin(acc_pin), balance(acc_balance) {}
        void displayInfo(){
            cout << "Username : " << username << endl;
            cout << "Pin : " << pin << endl;
            cout << "Balance : " << fixed << setprecision(2) << balance << endl;
        }
    
};
class SavingAccount : public Account{
    public:
        SavingAccount(string sacc_uname, string sacc_pin) : Account(sacc_uname, sacc_pin, 0.0){}
        
    };
    
class CurrentAccount : public Account{
    public:
        CurrentAccount(string cacc_uname, string cacc_pin) : Account(cacc_uname, cacc_pin, 0.0){}
};
class ATM{
    private:
    vector<SavingAccount> savingsAccounts;
    vector<CurrentAccount> currentAccounts;
    
};
int main(){
    SavingAccount s1("Pona Tona" , "345434");
    s1.displayInfo();
    return 0;
}