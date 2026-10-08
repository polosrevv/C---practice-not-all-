#include <iostream>

using namespace std;

int main(){
    // Declaring pointers
    // These are variables, but are not regular variables and are exclusive to other variable addresses

    // datatype*pointerName
    int * p_number; // This is a pointer made for stroing int variable addresses

    double * p_fractional_number; // for doubles

    // initalize to nullptr
    // A pointer that contains null cannot be used
    int * p_number1{nullptr};

    //all pointer variables have the same size in memory
    // difference between size and sizeof is size is the length, sizeof is memory size

    cout << "Size of number pointer: " << sizeof(p_number) << ", size of int: " << sizeof(int) << endl;
    cout << "Size of fractional_number pointer: " << sizeof(p_fractional_number) << ", size of double: " << sizeof(double) << endl;
    // The pointers themselves both have 8 bytes taken up in memory
    // The data types can vary but the pointers will always remain the same
    int var = 43;

    int *new_pointer{&var};
    cout << var << endl;
    cout << new_pointer << endl;

    int **newer_pointer{&new_pointer};
    cout << newer_pointer << endl;

    new_pointer++;
    cout << endl;
    cout << endl;
    cout << new_pointer << endl;
    cout << newer_pointer << endl;
    return 0;

}