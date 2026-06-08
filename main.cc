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
                    cout << "Login Successful" << endl;
                    return true;
                }
            }
            for(int i = 0; i < currentAccounts.size(); i++){
                if(currentAccounts[i].getUsername() == uname && currentAccounts[i].getPin() == pin){
                    loggedInAccount = &currentAccounts[i];
                    cout << "Login Successful" << endl;
                    return true;
                }
            }
            cout << "Login Unsuccessful" << endl;
            return false;
        }
        
        void logout(){
            loggedInAccount = nullptr;
            cout << "Logout Successful" << endl;
            
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
                    cout << "Insufficient Balance" << endl;
                    return;
            }
            cout << "No user logged in" << endl;
        }
        
        void displayLoggedInAccount(){
            if(isLoggedIn()){
                loggedInAccount->displayInfo();
            }
            else{
                cout << "No user logged in" << endl;
            }
        }

};

int main(){
    ATM a1;
    int choice;
    bool running = true;
    cout << "======== ATM ========" << endl;
    while(running){
        if(!a1.isLoggedIn()){
            cout << endl;
            cout << "======= ATM Main Menu =======" << endl;
            cout << endl;
            cout << "1. Create Account " << endl;
            cout << "2. Login " << endl;
            cout << "3. Exit " << endl;
            cout << "Enter Choice: ";
            cin >> choice;
            cout << endl;
    
            switch(choice){
                case 1:{
                    string u_name, u_pin;
                    int acc_type;
                    cout << "Enter Username: ";
                    cin.ignore();
                    getline(cin , u_name);
                    cout << "Enter Pin: ";
                    cin >> u_pin;
                    cout << endl;
                    cout << "Account type:" << endl;
                    cout << "   1. Savings Account" << endl;
                    cout << "   2. Current Account" << endl;
                    cout << "Enter : ";
                    cin >> acc_type;
                    a1.create_account(u_name, u_pin, acc_type);
                    cout << endl;  
                    break;
                }
                case 2:{
                    string u_name, u_pin;
                    cout << "Enter Username: ";
                    cin.ignore();
                    getline(cin , u_name);
                    cout << "Enter Pin: ";
                    cin >> u_pin;
                    cout << endl;
                    a1.login(u_name, u_pin);
                    break;
                }
                case 3:{
                    running = false;
                    cout << "THANK YOU";
                    break;
                }
                default: {cout << "Invalid choice" << endl;
                cout << endl;}
            }
        }
        else if(a1.isLoggedIn()){
            cout << endl;
            cout << "====== USER MENU ======" << endl;
            cout << endl;
            cout << "1. Deposit Money" << endl;
            cout << "2. Withdraw Money" << endl;
            cout << "3. Display Account Details" << endl;
            cout << "4. Logout" << endl;
            cout << "Enter Operation: ";
            cin >> choice;
            cout << endl;

            switch (choice){
            case 1:{
                double amount;
                cout << "Enter amount: ";
                cin >> amount;
                cout << endl;
                a1.depositToLoggedInAccount(amount);
                break;
            }
            case 2:{
                double amount;
                cout << "Enter amount: ";
                cin >> amount;
                cout << endl;
                a1.withdrawFromLoggedInAccount(amount);
                break;
            }
            case 3:{
                a1.displayLoggedInAccount();
                break;
            }
            case 4:{
                a1.logout();
                break;
            }
            default:{
                cout << "Invalid Operation" << endl;
                break;
            }
            }
        }
        else{
            cout << "Invalid Menu Choice" << endl;
        }
    }
    return 0;
}   