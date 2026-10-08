#include <iostream>
#include <limits>

int main() {
    std::cout << "Limits for int:" << std::endl;
    std::cout << "Min: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::endl;
    std::cout << "Limits for double:" << std::endl;
    std::cout << "Min: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << std::endl;
    std::cout << "int is signed : " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "int digits : " << std::numeric_limits<int>::digits << std::endl;
    std::cout<<std::endl;
    return 0;
}