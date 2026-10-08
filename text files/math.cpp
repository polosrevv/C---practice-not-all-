#include <iostream>
#include <cmath>


int main() {
    double weight = 7.7;
    std::cout << "Weight rounded to floor is: " << std::floor(weight) << std::endl;

    std::cout << "Weight rounded to ceiling is: " << std::ceil(weight) << std::endl;
    double savings = -5000;
    std::cout << "Abs of weight is: " << std::abs(weight) << std::endl;
    std::cout << "Abs of savings is: " << std::abs(savings) << std::endl;


    std::cout << "Weight rounded to the nearest int is: " << std::round(weight) << std::endl;

    double exponential = std::exp(weight);
    std::cout << "Exponential of weight is: " << exponential << std::endl;

    std::cout << "3^4 is: "<< std::pow(3,4) << std::endl;

    std::cout << "Log of weight is: " << std::log(weight) << std::endl;
    std::cout << "Log of savings is: " << std::log(std::abs(savings)) << std::endl;
    std::cout << "The square root of 81 is" << std::sqrt(81) << std::endl;
    std::cout << "The cube root of 27 is: " << std::cbrt(27) << std::endl;
    std::cout << "The fourth root of 81 is: " << std::pow(81, 1.0/4.0) << std::endl;
    
    return 0;

}