// Steven Gonell
// 8/22/26
// Constructor Practice

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Player{
    private:
        std::string name;
        int points;
        int rebounds;
    public:

    Player(){
        name = "New Player";
        points = 0;
        rebounds = 0;
    };

    Player(std::string playerName, int givenPoints, int rebounds): name(playerName), points(givenPoints){
        this->rebounds = rebounds;
    }
    void addPoints(int amount){
        if(amount < 0){
            std::cerr << "Cannot add negative points";
        }
        else{
            points += amount;
        }
    }
    int getPoints(){
        return points;
    }
    std::string getName(){
        return name;
    }

    void addRebounds(int amount){
        if(amount < 0){
            std::cerr << "Cannot add negative points";
        }
        else{
            rebounds += amount;
        }
    }
    int getRebounds(){
        return rebounds;
    }
    void setPoints(int points){
        if(points < 0){
            std::cerr << "Cannot have negative points";
        }
        else{
            this->points = points;
        }
        
    }
    void setRebounds(int rebounds){
        if(rebounds < 0){
            std::cerr << "Cannot have negative rebounds";
        }
        else{
            this->rebounds = rebounds;
        }
    }
};
Player player1("player1", 17, 5);
Player player2("player2", 25, 3);
Player player3("player3", 7, 9);

int main(){
    std::cout << player1.getName() << ": " << player1.getPoints() << std::endl; 
    std::cout << player2.getName() << ": " << player2.getPoints() << std::endl;
    std::cout << player3.getName() << ": " << player3.getPoints() << std::endl;

}

