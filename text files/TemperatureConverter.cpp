/*Temperature Converter: Prompt the user for a temperature in Celsius. 
Convert and print it in Fahrenheit using the formula \(F = (C \times 9/5) + 32\).*/

#include <iostream>

int main(){
int temp;

std::cout<< "Input a tempature in Celsius: ";
std::cin >> temp;

int newTemp = (temp*(9/5) + 32);

std::cout<< "Your tempature in Farenheit is: " << newTemp << std::endl;

return 0;
}