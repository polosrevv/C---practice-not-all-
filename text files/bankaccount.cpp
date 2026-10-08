// Steven Gonell
// 8/22/26
// Bank Account

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class bankAccount{
    private:
        double balance;
    
    public:
        void deposit(double amount){
            balance += amount;
        }

        void withdraw(double amount){
            if(amount > balance){
                std::cerr << "balance cannot be negative";
                
            }
            else{
                balance -= amount;
            }
            
        }
        double getBalance(){
            return balance;
        }
};
bankAccount account1;


bankAccount account2;

int main(){
    account1.deposit(1000);
    account1.withdraw(500);

    account2.deposit(800);
    account2.withdraw(200);

    std::cout << "Account 1" << std::endl;
    std::cout << "Balance: $" << account1.getBalance() << std::endl;
    
    std::cout << "Account 2" << std:: endl;
    std::cout << "Balance: $" << account2.getBalance() << std::endl;
}
