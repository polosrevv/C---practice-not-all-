#include <iostream>
int main(){
    int num1 = 55;
    int num2 = 60;

    bool result = (num1 < num2);

    std::cout << std::boolalpha << result << std::endl;

    std::cout << std::endl;
    std:: cout << "free standing if statement" << std::endl;

    //If (result)
    if(result == true){
        std::cout << num1 << " is less than " << num2 << std::endl;
    }
    else{
        std::cout << num1 << " is NOT less than " << num2 << std::endl;
    }
    
}