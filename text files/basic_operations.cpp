// Steven Gonell
// 08/07/2026
// Order of operations in C++

#include <iostream>
#include <ios>
#include <ostream>
#include <iomanip>
#include <limits>


int main() {
    // initialize variables
    int a = 3;
    int b = 5;
    int c = 12;
    int d = 11;
    int e = 8;
    int f = 14;
    int g = 4;
    int result = a+b*c-d/e-f+g;
    // in terms of order of operations, you'd first calculate b*c, then d/e, and finally perform the addition and subtraction
    // so you'd have b*c and d/e which is 60 and 1, and then for 60 you'd add 3, and then subtract 63 and 1 and then subtract 14 which gives us 48, and then you add 4 for 52
    std::cout << "result : " << result << std::endl;
    result = a/b*c + d - e + f; // im predicting that this will print 17
    // 3/5 = 0, 0*12 = 0, 0+11 = 11, 11-8 = 3, 3+14 = 17
    std::cout << "result : " << result << std::endl;
    result = a+(b*c)-(d/e)-f+g; 
    // 3+(60)-(1)-14+4 = 3+60-1-14+4 = 52
    std::cout << "result : " << result << std::endl;
    result = (a+b)*c - d/e - f + g;
    // (3+5)*12 - 11/8 - 14 + 4 = 8*12 - 1 - 14 + 4 = 96 - 1 - 14 + 4 = 85
    std::cout << "result : " << result << std::endl;


    // endl and /n both place a new line character on the output stream
    // They are both almost identical
    // this is similar to println in java(system.out.print = no endl/ /n, println is with endl or /n)

    std::cout << "Hello";
    std:: cout << "World";

    std:: cout << std:: endl;

    std::cout << "---------------" << std::endl;

    std::cout << "Hello" << std:: endl;

    std::cout << "World" << std::endl;

    std::cout << std::endl;

    std::cout << "Hello\n";
    std::cout << "World\n";

    std::cout << std::endl;
    std::cout << "This is a nice little hidden message" << std:: endl << std::flush;

    //Unformatted table example: 

    std::cout << "Unformatted table : " << std::endl;
    std::cout << "Daniel" << " " << "Gray" << " 25" << std::endl;
    std::cout << "John" << " " << "Doe" << " 30" << std::endl;
    std::cout << "Jane" << " " << "Smith" << " 28" << std::endl;
    std::cout << std::endl;

    //Formatted table example using setw: 

    std::cout << "Formatted table : " << std::endl;
    std::cout << std::setw(10) << "Name " << std::setw(8) << "Last Name" << std::setw(5) << "Age" << std::endl;
    std::cout << std::setw(10) << "Daniel" << std::setw(8) << "Gray" << std::setw(5) << "25" << std::endl;
    std::cout << std::setw(10) << "John" << std::setw(8) << "Doe" << std::setw(5) << "30" << std::endl;
    std::cout << std::setw(10) << "Jane" << std::setw(8) << "Smith" << std::setw(5) << "28" << std::endl;

    // Formatted table example using variables instead of literals:
    // initialize a variable for column width(this is more efficient)
    int col_width = 14;
    std::cout << "Formatted table with variables : " << std::endl;

    std::cout << std::setw(col_width) << "First Name" << std::setw(col_width) << "Last Name" << std::setw(col_width) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << "25" << std::endl;
    std::cout << std::setw(col_width) << "John" << std::setw(col_width) << "Doe" << std::setw(col_width) << "30" << std::endl;
    std::cout << std::setw(col_width) << "Jane" << std::setw(col_width) << "Smith" << std::setw(col_width) << "28" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;



    // Right justified(this is the default)

    std::cout << std::right; // Right justify
    std::cout << std::setw(col_width) << "First Name" << std::setw(col_width) << "Last Name" << std::setw(col_width) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << "25" << std::endl;
    std::cout << std::setw(col_width) << "John" << std::setw(col_width) << "Doe" << std::setw(col_width) << "30" << std::endl;
    std::cout << std::setw(col_width) << "Jane" << std::setw(col_width) << "Smith" << std::setw(col_width) << "28" << std::endl;

    std::cout << std::endl;

    // Left justified
    std::cout << std::left; // Left justify
    std::cout << std::setw(col_width) << "First Name" << std::setw(col_width) << "Last Name" << std::setw(col_width) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << "25" << std::endl;
    std::cout << std::setw(col_width) << "John" << std::setw(col_width) << "Doe" << std::setw(col_width) << "30" << std::endl;
    std::cout << std::setw(col_width) << "Jane" << std::setw(col_width) << "Smith" << std::setw(col_width) << "28" << std::endl;

    std::cout << std::endl;

    // Table with fill characters
    std::cout << std::setfill('*') << std::setw(col_width) << "First Name" << std::setw(col_width) << "Last Name" << std::setw(col_width) << "Age" << std::endl;
    std::cout << std::setfill('*') << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << "25" << std::endl;
    std::cout << std::setfill('*') << std::setw(col_width) << "John" << std::setw(col_width) << "Doe" << std::setw(col_width) << "30" << std::endl;
    std::cout << std::setfill('*') << std::setw(col_width) << "Jane" << std::setw(col_width) << "Smith" << std::setw(col_width) << "28" << std::endl;

    std::cout << std::endl;
    std::cout.fill(' ');
    // boolalpha
    std::cout << std::boolalpha;
    std::cout << std::setw(col_width) << "Is Adult" << std::setw(col_width) << "Is Student" << std::endl;
    std::cout << std::setw(col_width) << true << std::setw(col_width) << false << std::endl;
    std::cout << std::setw(col_width) << false << std::setw(col_width) << true << std::endl;
    std::cout << std::endl;

    //showpos
    std::cout << std::showpos;
    std::cout << std::setw(col_width) << "Value" << std::endl;
    std::cout << std::setw(col_width) << 42 << std::endl;
    std::cout << std::setw(col_width) << -42 << std::endl;

    std::cout << std::endl;


    //printing varaibles in diff bases

    int pos_int = 42;
    int neg_int = -42;
    std::cout << std::endl;
    std::cout << "Decimal: " << pos_int << std::dec << "," << neg_int << std::endl;
    std::cout << "Hexadecimal: " << std::hex << pos_int << ", " << std::hex << neg_int << std::endl;
    std::cout << "Octal: " << std::oct << pos_int << ", " << std::oct << neg_int << std::endl;
    return 0;

}