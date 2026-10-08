#include <iostream>
#include <string>
#include <vector>
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

        }
        std::string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        virtual void introduce(){
            std::cout << "I am a person!";
        }
};

void introducePerson(Person &person){
            person.introduce();
}
class Player : public Person{
    private:
        int jerseyNumber;
        int points;
    public:
        Player(){
            jerseyNumber = 1;
            points = 0;
        };
        Player(std::string name, int age, int jerseyNumber, int points) : Person(name, age) , jerseyNumber(jerseyNumber), points(points){

        }
        int getJerseyNumber(){
            return jerseyNumber;
        }
        int getPoints(){
            return points;
        }
        void introduce() override{
            std::cout << "I am a player!";
        }
};

class Coach : public Person{
    private:
        int yearsCoaching;
    public:
        Coach(){
            yearsCoaching = 0;
        }
        Coach(std::string name, int age, int yearsCoaching) : Person(name, age) , yearsCoaching(yearsCoaching){

        }
        int getYearsCoaching(){
            return yearsCoaching;
        }
        void introduce() override{
            std::cout << "I am a Coach!";
        }
};

class Team{
    private:
        std::vector<Person>people;
        std::vector<Player> players;
        std::vector<Coach> coaches;
        int wins;
        int losses;
    public:
        Team(int wins, int losses) : wins(wins), losses(losses){

        }
        void getRoster(){
            for(Person i : people){
                std::cout << i.getName() << std::endl;
                std::cout << i.getAge() << std::endl;
                i.introduce();
            }
            
        }
        int getWins(){
            return wins;
        }
        int getLosses(){
            return losses;
        }
        double getWinPercentage(){
            return (static_cast<double>(wins)/(static_cast<double>(wins)+static_cast<double>(losses))) * 100;
        }
};

int main(){
    Player steven("Steven", 16, 11, 25);
    Coach coach("Coach", 35, 8);
    introducePerson(steven);
    introducePerson(coach);
    std::cout << coach.getName() << std::endl;
    std::cout << coach.getAge() << std::endl;
    std::cout << coach.getYearsCoaching() << std::endl;
    Person* person1 = &steven;
    Person* person2 = &coach;
    person1->introduce();
    person2->introduce();
    std::cout << steven.getName() << std::endl;
    std::cout << steven.getAge() << std::endl;
    std::cout << steven.getJerseyNumber() << std::endl;
    std::cout << steven.getPoints() << std::endl;
}