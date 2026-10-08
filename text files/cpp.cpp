#include <iostream>

int main() {
    // __cplusplus yields a YYYYMM long integer representing the standard version
    long version = __cplusplus;
    
    if (version == 199711L) std::cout << "Using C++98\n";
    else if (version == 201103L) std::cout << "Using C++11\n";
    else if (version == 201402L) std::cout << "Using C++14\n";
    else if (version == 201703L) std::cout << "Using C++17\n";
    else if (version == 202002L) std::cout << "Using C++20\n";
    else if (version == 202302L) std::cout << "Using C++23\n";
    else if (version > 202302L)  std::cout << "Using a preview of a newer standard (C++26)\n";
    else std::cout << "Using an unknown/pre-standard C++: " << version << "\n";
    
    return 0;
}
