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

        void deposit(double amount){ balance += amount; }

        bool withdraw(double amount){
            if(balance-amount >= 0){
                balance -= amount;
                return true;
            }
            return false;
        }
        
        string getusername(){
            return username;
        }
        string getpin(){
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
    public:
        void create_account(string uname, string pinn, int accountType){
            if(accountType == 1){
                SavingAccount s1(uname , pinn);
                savingsAccounts.push_back(s1);
            } 
            if(accountType == 2){
                CurrentAccount c1(uname , pinn);
                currentAccounts.push_back(c1);
            } 
        }

        void displayAll(){      // display all accounts of savings and current
            for(int i = 0; i < savingsAccounts.size(); i++){
                savingsAccounts[i].displayInfo();
            }
            cout << endl;
            for(int i = 0; i < currentAccounts.size(); i++){
                currentAccounts[i].displayInfo();
            }
        }

        bool login(string uname, string pin){
            int i;
            for(i = 0; i < savingsAccounts.size(); i++){
                if(savingsAccounts[i].getusername() == uname && savingsAccounts[i].getpin() == pin){
                    return true;
                }
            }
            for(i = 0; i < currentAccounts.size(); i++){
                if(currentAccounts[i].getusername() == uname && currentAccounts[i].getpin() == pin){
                    return true;
                }
            }
            return false;
        }
};

int main(){
    ATM c1;
    c1.create_account("Pona Tona", "456587", 1);
    c1.displayAll();
    return 0;
}