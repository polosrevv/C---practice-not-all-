// Steven Gonell
// 8/22/26
// Inheritance Practice

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Person{
    private:
        std::string name;
        int age;
    public:
        Person(){
            name = "New Person";
            age = 18;
        }
        Person(std::string name, int age) : name(name), age(age){

        };
        std::string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        virtual void introduce(){
            std::cout << "I am a person!" << std::endl;
        }
};

class Player : public Person{
    private:
        int points;
        int jerseyNumber;
    public:
        Player(std::string name, int age, int points, int jerseyNumber) : Person( name, age), points(points), jerseyNumber(jerseyNumber){

        };
        int getPoints(){
            return points;
        }
        int getJerseyNumber(){
            return jerseyNumber;
        }
        void introduce() override{
            std::cout << "I am a Player!" << std::endl;
        }
};

class Coach : public Person{
    private:
        int yearsCoaching;
        int playoffAppearances;
    public:
        Coach(std::string name, int age, int years, int appearances) : Person(name, age), yearsCoaching(years), playoffAppearances(appearances){

        }
        void introduce() override{
            std::cout << "I am a coach!" << std::endl;
        }
};

int main(){
    Player steven("Steven", 16, 20, 11);
    Player zael("Zael", 18, 26, 22);
    Player eddy("Edson", 17, 3, 20);
    Person example("randomdude", 18);
    Coach dudeCoach("Coach1", 35, 3, 2);
    Person* stevenPointer = &steven;
    Person* coachPointer  = &dudeCoach;
    coachPointer->introduce();
    example.introduce();
    steven.introduce();
    stevenPointer->introduce();
    std::cout << steven.getAge() << std::endl;
    std::cout << steven.getPoints() << std::endl;
    std::cout << steven.getName() << std::endl;
    
}
