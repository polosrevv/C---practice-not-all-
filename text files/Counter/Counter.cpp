#include "Counter.h"
#include <iostream>

int main(){
Counter a(10);
Counter b(5);

Counter c = a + b;

std::cout << c << '\n';

a += b;

std::cout << a << '\n';

if (a == c) {
    std::cout << "Equal\n";
}
}