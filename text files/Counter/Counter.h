#include <iostream>

// Creating the class Counter
class Counter{
    // Declaring value as private only to be manipulated via operators and declaring a Counter object
    private:    
        int value;
    public:
    // Constructor to allow Object creation(init is my preferred method, unless I explcitly have to give something a specific default value)
        Counter(int value) : value(value){

        }
        // This probably isn't needed
        int getValue() const{
            return this->value;
        }
        // I forgot how to use operators so im reasoning it through
        Counter operator+(const Counter& other) const{
            return Counter(this->value + other.value);
        }
        Counter operator+=(Counter& other){
            // *this should point to the object as a whole
            this->value += other.value;
            return *this;
        }
        bool operator==(const Counter& other) const{
            if(this->value == other.value){
                return true;
            }
            else{
                return false;
            }
        }
};
 std::ostream& operator<<(std::ostream& out, const Counter& counter){
            out << counter.getValue();
            return out;
        }