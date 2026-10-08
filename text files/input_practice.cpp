// Steven Gonell
// 8/07/2026
// This program takes an age as input and outputs the age category and whether the age is even or odd.
// First time using inputs in C++ so I am not sure if this is the best way to do it but it works.
// Also testing out error handling for negative ages.
#include <iostream>

bool isEven(int age){
	return age % 2 == 0;
}

int main() {
	std::cout << "Enter a age: ";
	int age;
	std::cin >> age;
	if (age < 0) {
		std::cerr << "Age cannot be negative." << std::endl;
		return 1;
	}
	else if (age < 13) {
		std::cout << "You are a child." << std::endl;
		std::clog << "Child age: " << age << std::endl;
	}
	else if (age < 20) {
		std::cout << "You are a teenager." << std::endl;
		std::clog << "Teenager age: " << age << std::endl;
	}
	else if (age < 65) {
		std::cout << "You are an adult." << std::endl;
		std::clog << "Adult age: " << age << std::endl;
	}
	else {
		std::cout << "You are a senior." << std::endl;
		std::clog << "Senior age: " << age << std::endl;
	}
	if (isEven(age)) {
		std::cout << "Your age is even." << std::endl;
	}
	else {
		std::cout << "Your age is odd." << std::endl;
	}
    std::cin.get();
	return 0;
}