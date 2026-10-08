// Steven Gonell
// 8/07/2026
// more binary practice, looks really similar to the first one lol
#include <iostream>

int main(){
    // initialize the variables
    int num1 = 15; //decimal
    int num2 = 017; // octal
    int num3 = 0x0F; //hexadecimal
    int num4 = 0b00001111; //binary

    // display the values

    std::cout << "Decimal: " << num1 << std::endl;
    std::cout << "Octal: " << num2 << std::endl;
    std::cout << "Hexadecimal: " << num3 << std::endl;
    std::cout << "Binary: " << num4 << std::endl;

    // retrieve size in memory of the first two variables

    std:: cout << "Size of num1: " << sizeof(num1) << " bytes" << std::endl;
    std:: cout << "Size of num2: " << sizeof(num2) << " bytes" << std::endl;
    return 0;
}
