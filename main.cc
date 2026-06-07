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
            cout << endl;
        }

        void deposit(double amount){ balance += amount; }

        bool withdraw(double amount){
            if(balance-amount >= 0){
                balance -= amount;
                return true;
            }
            return false;
        }
        
        string getUsername(){
            return username;
        }
        string getPin(){
            return pin;
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

    Account* loggedInAccount = nullptr;

    public:
        void create_account(string uname, string pinn, int accountType){
            if(accountType == 1){
                SavingAccount s1(uname , pinn);
                savingsAccounts.push_back(s1);
                cout << "Account creation successfull" << endl;
            } 
            else if(accountType == 2){
                CurrentAccount c1(uname , pinn);
                currentAccounts.push_back(c1);
                cout << "Account creation successfull" << endl;
            } 
            else{
                cout << "Invalid Account type" << endl;
            }
        }

        void displayAll(){      // display all accounts of savings and current
            for(int i = 0; i < savingsAccounts.size(); i++){
                savingsAccounts[i].displayInfo();
            }
            for(int i = 0; i < currentAccounts.size(); i++){
                currentAccounts[i].displayInfo();
            }
        }

        bool login(string uname, string pin){
            if(isLoggedIn()){
                cout << "User "  << loggedInAccount->getUsername() << " already logged in" << endl;
                return false;
            }
            for(int i = 0; i < savingsAccounts.size(); i++){
                if(savingsAccounts[i].getUsername() == uname && savingsAccounts[i].getPin() == pin){
                    loggedInAccount = &savingsAccounts[i];
                    return true;
                }
            }
            for(int i = 0; i < currentAccounts.size(); i++){
                if(currentAccounts[i].getUsername() == uname && currentAccounts[i].getPin() == pin){
                    loggedInAccount = &currentAccounts[i];
                    return true;
                }
            }
            return false;
        }

        void logout(){
            loggedInAccount = nullptr;
        }

        bool isLoggedIn(){
            return loggedInAccount != nullptr;
        }

        void depositToLoggedInAccount(double amount){
            if(isLoggedIn()){
                loggedInAccount->deposit(amount);
                cout << "Deposit successfull" << endl;
            }
            else{
                cout << "error in deposit" << endl;
            }   
        }
        
        void withdrawFromLoggedInAccount(double amount){
            if(isLoggedIn()){
                if(loggedInAccount->withdraw(amount)){
                    cout << "Withdraw successfull" << endl;
                    return;
                }
                    cout << "error in Withdraw" << endl;
                    return;
            }
            cout << "No user logged in" << endl;
        }

        void displayLoggedInAccount(){
            if(isLoggedIn()){
                loggedInAccount->displayInfo();
            }
        }

};

int main(){
    ATM c1;
    c1.create_account("Pona Tona", "456587", 1);
    c1.create_account("Bamberbola", "989221", 1);
    c1.create_account("Cucubamber", "687445", 2);
    c1.login("Cucubamber", "687445");
    c1.depositToLoggedInAccount(50000);
    c1.withdrawFromLoggedInAccount(2000);
    c1.displayLoggedInAccount();
    // c1.logout();
    c1.login("Cucubamber", "687445");
    return 0;
}   