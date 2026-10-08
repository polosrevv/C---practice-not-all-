#include <iostream>

int main() {
    int day;
    std::cout << "Enter a day of the week (1-7): ";
    std::cin >> day;

    switch(day) {
        case 1:
            std::cout << "This is sunday" << std:: endl;
            break;
        case 2:
            std::cout << "This is monday" << std:: endl;
            break;
        case 3:
            std::cout << "This is tuesday" << std:: endl;
            break;
        case 4:
            std::cout << "This is wednesday" << std::endl;
            break;
        case 5:
            std::cout << "This is thursday" << std::endl;
            break;
        case 6:
            std::cout << "This is friday" << std::endl;
            break;
        case 7:
            std::cout << "This is saturday" << std::endl;
            break;
        default:
            std::cout << "This is not a valid integer" << std::endl;
            break;
    }

}