// Steven Gonell
// 8/07/2026
// Learning about doubles in C++

#include <iostream>

// three different ways of storing fractional numbers
float number1 = 1.3211231234f;
double number2 = 1.321123123456789;
long double number3 = 1.321123123456789012345678901234567890L;

// Function to add two decimals
long double addNumbers(long double a, long double b) {
    return a + b;
}
int main() {
    //display the results
    std::cout << "Float: " << number1 << std::endl;
    std::cout << "Double: " << number2 << std::endl;
    std::cout << "Long Double: " << number3 << std::endl;

    //display the sizes
    std::cout << "Size of Float: " << sizeof(number1) << " bytes" << std::endl;
    std::cout << "Size of Double: " << sizeof(number2) << " bytes" << std::endl;
    std::cout << "Size of Long Double: " << sizeof(number3) << " bytes" << std::endl;

    // adding doubles, floats, and long doubles together using the function addNumbers
    long double result = addNumbers(number2, number3);
    std::cout << "Sum of Double and Long Double: " << result << std::endl;
    long double result2 = addNumbers(number1, number2);
    std::cout << "Sum of Float and Double: " << result2 << std::endl;

    return 0;
}