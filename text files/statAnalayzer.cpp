// Steven Gonell
// 8/19/26
// Stat Analyzer
// 93/100

// Libraries
#include <iostream>
#include <string>
#include <iomanip>

// Variables

// Player object

struct Player{
    std::string playerName;
    int jerseyNumber;
    int fieldGoals;
    int fieldGoalAttempts;
    int threePointers;
    int threePointersAttempted;
    int freeThrows;
    int freeThrowsAttempted;
    bool scored20;
    bool shot50FromField;
    bool shot40FromThree;
    int pointsScored;
    // Percentages

    double fgPercentage;
    double freeThrowPercentage;
    double threePointPercentage;
    double trueShootingPercentage;
    std::string rating;

};
int playerCount;
//Functions

int pointsScored(Player p){
    return (p.fieldGoals - p.threePointers) * 2 + p.threePointers * 3 + p.freeThrows;
}

double fieldGoalPercentage(Player p){
    return static_cast<double>(p.fieldGoals) /p.fieldGoalAttempts * 100;
}

double threePointPercentage(Player p){
    return static_cast<double>(p.threePointers)/p.threePointersAttempted * 100;
}

double freeThrowPercentage(Player p){
    return static_cast<double>(p.freeThrows)/p.freeThrowsAttempted * 100;
}

double trueShootingPercentage(Player p){
    return p.pointsScored/(2*(p.fieldGoalAttempts+0.44*p.freeThrowsAttempted)) * 100;
}



void playerRating(Player& p){
    int performanceScore = 0;

    if(p.scored20){
        performanceScore += 25;
    }

    if(p.shot50FromField){
        performanceScore += 10;
    }
    if(p.shot40FromThree){
        performanceScore += 15;
    }

    // FT %
    // Free Throw Percentage is a variable im gonna declare later on
    if(p.freeThrowPercentage >= 80 && p.freeThrowPercentage < 90){
        performanceScore += 5;
    }
    else if(p.freeThrowPercentage >= 90){
        performanceScore +=10;
    }

    // Threes made

    if(p.threePointers >= 2 && p.threePointers <= 5){
        performanceScore += 15;
    }

    else if(p.threePointers >= 6 && p.threePointers <= 7){
        performanceScore += 20;
    }

    else if(p.threePointers >= 8 && p.threePointers < 10){
        performanceScore += 25;
    }

    else if(p.threePointers >= 10){
        performanceScore += 30;
    }

    // True shooting % using the official formula
    if(p.trueShootingPercentage >= 56 && p.trueShootingPercentage < 60){
        performanceScore +=5;
    }

    else if(p.trueShootingPercentage >= 60 && p.trueShootingPercentage < 65){
        performanceScore += 8;
    }

    else if(p.trueShootingPercentage >= 65 && p.trueShootingPercentage < 70){
        performanceScore +=13;
    }

    else if(p.trueShootingPercentage >= 70 && p.trueShootingPercentage < 75){
        performanceScore +=15;
    }

    // making sure the score isn't over 100
    if(performanceScore > 100){
        performanceScore = 100;
    }

    int scoreLevel;
    if(performanceScore <=39){
        scoreLevel = 0;
    }
    else if(performanceScore <=59){
        scoreLevel = 1;
    }
    else if(performanceScore <=74){
        scoreLevel = 2;
    }
    else if(performanceScore <=89){
        scoreLevel = 3;
    }
    else if(performanceScore <=100){
        scoreLevel = 4;
    }
    //applying a category to each score
    switch(scoreLevel){
        case 0:
            p.rating = "Poor";
            break;
        case 1:
            p.rating = "Below Average";
            break;
        case 2:
            p.rating = "Solid";
            break;
        case 3:
            p.rating = "Great";
            break;
        case 4:
            p.rating = "Elite";
            break;
    }


}

// Formatted report for all the players
void playerReport(Player p){
    std::cout << "============= Team Report =============" << std::endl;
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(1);


    std::cout << std::setw(8) << "#" << p.jerseyNumber << " " << std::setw(8) << p.playerName << std::endl;
    std::cout << std::setw(8) << "Points: " << p.pointsScored << std::endl;
    std::cout << std::setw(8) << "FG: " << p.fieldGoals << "/" << p.fieldGoalAttempts << " (" << p.fgPercentage << "%)" << std::endl;
    std::cout << std::setw(8) << "3PT: " << p.threePointers << "/" << p.threePointersAttempted << " (" << p.threePointPercentage << "%)" << std::endl;
    std::cout << std::setw(8) << "FT: " << p.freeThrows << "/" << p.freeThrowsAttempted << " (" << p.freeThrowPercentage << "%)" << std::endl;
    std::cout << std::setw(8) << "TS: " << p.trueShootingPercentage << "%" << std::endl;
    std::cout << std::setw(8) << "Rating: " << p.rating << std::endl;
    std::cout << std::endl;
}

void teamBests(const Player p[]){
    double maxPoints = 0;
    double maxThree = 0;
    double maxTS = 0;
    std::string topScorer;
    std::string topShooter;
    std::string topEffiency;
    for(int i{};i < playerCount;i++){
        if(p[i].pointsScored > maxPoints){
            maxPoints = p[i].pointsScored;
            topScorer = p[i].playerName;
        }
        if(p[i].threePointers > maxThree){
            maxThree = p[i].threePointPercentage;
            topShooter = p[i].playerName;
        }
        if (p[i].trueShootingPercentage > maxTS){
            maxTS = p[i].trueShootingPercentage;
            topEffiency = p[i].playerName;
        }
    
    }
    std::cout << "=======================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(1) << std::setw(8);

    std::cout << "Best Scorer: " << topScorer << " (" << maxPoints << ")" << std::endl;
    std::cout << "Best 3PT%: " << topShooter << " (" << maxThree << "%)" << std::endl;
    std::cout << "Best effiency: " << topEffiency << " (" << maxTS << "%)" << std::endl;
}

// Main function
int main(){
    

    // asking for players

    std::cout << "How many players do you want to enter: ";
    std::cin >> playerCount;
    if(playerCount < 1 || playerCount > 15){
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

    // Creating an Array of players with the Player object(in order to assign each indivisual variable to each player)

    Player players[playerCount];
    // Using a for loop of input in order to ask each value for each player, each iteration is a new player

    for(int i{};i<playerCount;i++){
        std::cout << "Player " << i+1 << std:: endl;
        std::cout << "Whats the players name: ";
        std::cin.ignore();
        std::getline(std::cin , players[i].playerName);

        std::cout << std::endl;
        std::cout << "Whats the player Jersey Number: ";
        std::cin >> players[i].jerseyNumber;
        std::cout << std::endl;
        
        std::cout << "How many field goals did they make: ";
        std::cin >> players[i].fieldGoals;
        std::cout << std::endl;

        std::cout << "How many field goals did they attempt: ";
        std::cin >> players[i].fieldGoalAttempts;
        if(players[i].fieldGoalAttempts < players[i].fieldGoals){
            std::cerr << "Invalid attempts";
            return 1;
        }
        std::cout << std::endl;

        std::cout << "How many threes did they make: ";
        std::cin >> players[i].threePointers;
        if(players[i].threePointers > players[i].fieldGoals){
            std::cerr << "Invalid three point makes";
            return 1;
        }
        std::cout << std::endl;

        std::cout << "How many did they attempt: ";
        std:: cin >> players[i].threePointersAttempted;
        if(players[i].threePointersAttempted < players[i].threePointers || players[i].threePointersAttempted > players[i].fieldGoalAttempts){
            std::cerr << "Invalid three point attempts";
            return 1;
        }
        std:: cout << std::endl;

        std::cout << "How many free throws did they make: ";
        std::cin >> players[i].freeThrows;
        std::cout << std::endl;

        std:: cout << "How many free throws did they attempt?";
        std::cin >> players[i].freeThrowsAttempted;
        if(players[i].freeThrowsAttempted < players[i].freeThrows){
            std::cerr <<  "Invalid attempts";
            return 1;
        }
        std::cout << std::endl;

        // Percentage Calculations
        players[i].pointsScored = pointsScored(players[i]);
        players[i].fgPercentage = fieldGoalPercentage(players[i]);
        players[i].threePointPercentage = threePointPercentage(players[i]);
        players[i].freeThrowPercentage = freeThrowPercentage(players[i]);
        players[i].trueShootingPercentage = trueShootingPercentage(players[i]);
        
        // Boolean calculations
        if(players[i].pointsScored >= 20){
            players[i].scored20 = true;
        }
        else{
            players[i].scored20 = false;
        }
        if(players[i].fgPercentage >= 50){
            players[i].shot50FromField = true;
        } 
        else{
            players[i].shot50FromField = false;
        }
        if(players[i].threePointPercentage >= 40){
            players[i].shot40FromThree = true;
        } 
        else{
            players[i].shot40FromThree = false;
        }
        playerRating(players[i]);
        
        
    }
    for(int i{}; i < playerCount; i++){
        playerReport(players[i]);
    }

    teamBests(players);
}