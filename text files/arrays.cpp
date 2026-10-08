// Steven Gonell
#include <iostream>
#include <ios>
#include <ostream>
#include <iomanip>
#include <limits>

using namespace std;
int main(){
    // How to declare an array
    int scores[10]{};

    scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;

    for(int i{};i< size(scores);i++){
        scores[i] *= 3;
    }
    cout << endl;
    // Reading values
    cout << "Reading out score values(manually): " << endl;
    cout << "Scores[0]: " << scores[0] << endl;
    cout << "Scores[1]: " << scores[1] << endl;
    cout << "Scores[2]: " << scores[2] << endl;


    //Reading out score values(automatically using a for loop)
    for(int i{}; i<size(scores);i++){
            cout << "Scores" << "[" << i << "]: " << scores[i] << endl;
    }
    cout << size(scores) << endl;
    return 0;
}