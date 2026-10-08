// Steven Gonell
// 8/22/26
// Composition Practice

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Player{
    private:
        std::string name;
        int points;

    public:
        Player(){
            name = "New Player";
            points = 0;
        }
        Player(std::string newName, int newPoints) : name(newName), points(newPoints){

        };

        std::string getName(){
            return name;
        }
        int getPoints(){
            return points;
        }
};

class Team{
    private:
        std::string teamName;
        std::vector<Player> players;
    public: 
    

    Team(){
        teamName = "New Team";
    }
    Team(std::string teamName) : teamName(teamName){

    }
    void addPlayer(Player p){
        players.push_back(p);
    }
    void printPlayers(){
        for(Player i : players){
            std::cout << i.getName() << std::endl;
        }
    }
    void printRoster(){
        std::cout << teamName << std::endl;
        std::cout << "====================";
        std::cout << std::left << std::setw(15);
        for(Player& i : players){
            std::cout << i.getName() << std::setw(8) << i.getPoints();
        }
    }
    int getTotalPoints(){
        int sum = 0;
        int points = 0;
        for(Player& i : players){
            points = i.getPoints();
            sum += points;
        }
        return sum;
    }
    int getTotalPlayerCount(){
        int count = 0;
        for(Player& i : players){
            count++;
        }
        return count;
    }
};

int main(){
    Team Lakers;
    Player Lebron("Lebron James", 25);
    Player Curry("Stephen Curry", 31);
    Player KD("Kevin Durant", 27);

    Lakers.addPlayer(Lebron);
    Lakers.addPlayer(Curry);
    Lakers.addPlayer(KD);

    Lakers.printRoster();
    std::cout << Lakers.getTotalPoints();
    std::cout << Lakers.getTotalPlayerCount();
}