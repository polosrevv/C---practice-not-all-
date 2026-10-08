// Steven Gonell
// 8/20/26
// Grade Tracker
// practice


// Libraries
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


// Student variables

struct Student{
    std::string name;
    int grade;
};
// Creating vector for students to be stored

std::vector<Student> student;


// Functions

void printStudentResults(const std::vector<Student>& students){
    std::cout << "=====================" << std::endl;
    std::cout << std::setw(8) << "Name" << std::setw(8) << "Grade" << std::endl;
    for(Student i : students){
        std::cout << std::fixed << std::setprecision(1);
        std::cout << std::setw(8) << i.name << std::setw(8) << i.grade << std::endl;
    }
}
double calculateGradeAverage(const std::vector<Student>& students){
    int sum = 0;
    for(Student i : students){
        sum += i.grade;
    }
    if(students.size() <= 0){
        std::cerr << "Invalid list size";
        return 1;
    }
    double gradeAverage = static_cast<double>(sum)/students.size();
    return gradeAverage;
}
void printGradeAverage(const std::vector<Student>& students){
    std::cout << "========== Grade Average ==========" << std::endl;
    std::cout << "Class average: " << calculateGradeAverage(students);
}

void printHighestandLowestGrades(const std::vector<Student> & students){
    int min = 100;
    int max = 0;
    std::string highStudentName;
    std::string lowStudentName;
    for(Student i : students){
        if(i.grade <= min){
            min = i.grade;
            lowStudentName = i.name;
        }
        if(i.grade >= max){
            max = i.grade;
            highStudentName = i.name;
        }
    }
    std::cout << "========== Highest/Lowest Grades ==========" << std::endl;
    std::cout << std::setw(8) << "Highest" << std::setw(8) << "Lowest" << std::endl;
    std::cout << std::setw(8) << highStudentName << std::setw(8) << lowStudentName << std::endl;
    std::cout << std::setw(8) << max << std::setw(8) << min << std::endl;
}

// Program itsself
int main(){


    // user input for the class
    for(int i{};i<3;i++){
        Student j;
        std::cout << "Name: ";
        std::cin >> j.name;
        std::cout << std::endl;

        std::cout << "Grade: ";
        std::cin >> j.grade;
        std::cout << std::endl;

        student.push_back(j);
    }
    // function calls
    printStudentResults(student);
    printGradeAverage(student);

}