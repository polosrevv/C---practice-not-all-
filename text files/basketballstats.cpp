// Steven Gonell
// 8/10/2026
// This is a self administered exam, ill have my score under this
// 91/100

#include <iostream>
#include <string>
#include <ios>
#include <ostream>
#include <iomanip>
int main(){
    // Creating variables from user input
    // Also includes error checking
    
    //Ask for players name
    std::cout << "Input a player name: ";
    std::string playerName;
    std::cin >> playerName;
    std::cout<<std::endl;

    //Asking for Jersey #
    std::cout << "Whats his/her jersey number: ";
    int jerseyNumber;
    std::cin >> jerseyNumber;
    if(jerseyNumber > 99 || jerseyNumber < 0){
        std::cerr << "Invalid Jersey Number";
        return 1;
    }
    std::cout<< std::endl;

    //Player position 
    char position;
    std::cout << "What is the player's position? (G/F/C): ";
    std::cin >> position;
    if(position != 'G' && position != 'F' && position != 'C'){
    std::cerr << "Invalid position";
    return 1;
    }

    // Asking for field goal attempts
    std::cout << "How many field goals did you make?: ";
    int fieldGoalAttempts;
    std:: cin >> fieldGoalAttempts;
    //Explaining this once since it shows up in the rest, but any number other than +/- cannot be negative in basketball
    if(fieldGoalAttempts < 0){
        std::cerr << "Invalid field goal attmepts";
        return 1;
    }
    std::cout<<std::endl;


    // Asking for makes
    std::cout << "Of those attempts, how many did you make: ";
    int fieldGoalsMade;
    std::cin >> fieldGoalsMade;
    //Can't have more field goal makes than attempts ofc
    if(fieldGoalsMade > fieldGoalAttempts || fieldGoalsMade < 0){
        std::cerr << "Invalid field goal attempts";
        return 1;
    }
    // Threes attmepted
    std::cout << "How many threes did you attempt: ";
    int threesAttempted;
    std::cin >> threesAttempted;
    if(threesAttempted < 0 || threesAttempted > fieldGoalAttempts){
        std::cerr << "Invalid three point attempts";
        return 1;
    }
    std::cout << std:: endl;
    
    // Three point makes
    std::cout << "Of those threes, how many did you make: ";
    int threesMade;
    std::cin >> threesMade;
    if(threesMade > threesAttempted || threesMade < 0 || threesMade > fieldGoalsMade || threesMade > fieldGoalAttempts){
        std::cerr << "Invalid three point makes";
        return 1;
    }
    std::cout << std::endl;

    // Free throw attempts
    std::cout << "How many free throws were attempted: ";
    int freeThrowAttempts;
    std::cin >> freeThrowAttempts;
    if(freeThrowAttempts < 0){
        std::cerr << "Invalid free throw attempts";
        return 1;
    }
    std::cout << std::endl;
    
    // Free throw makes
    std::cout << "Of thos free throws, how many free throws were made: ";
    int freeThrowsMade;
    std::cin >> freeThrowsMade;
    if(freeThrowsMade > freeThrowAttempts || freeThrowsMade < 0){
        std::cerr << "Invalid free throw makes";
        return 1;
    }
    std::cout << std::endl;

    // Calculation

    double fieldGoalPercentage = (static_cast<double>(fieldGoalsMade) / fieldGoalAttempts)*100;
    double threePointPercentage = (static_cast<double>(threesMade) / threesAttempted)*100;
    double freeThrowPercentage = (static_cast<double>(freeThrowsMade) / freeThrowAttempts) * 100;
    auto twoPointersAttempted = fieldGoalAttempts - threesAttempted;
    auto twoPointersMade = fieldGoalsMade - threesMade;
    auto totalPoints = (twoPointersMade * 2) + (threesMade * 3) + freeThrowsMade;
    bool scored20 = (totalPoints >= 20);
    bool shot50FromField = (fieldGoalPercentage >= 50);
    bool shot40FromThree = (threePointPercentage >= 40);
    double trueShooting = totalPoints/(2*(fieldGoalAttempts+0.44*freeThrowAttempts)) * 100;
    

    // Calculating score

    // Declaring variable for score
    int performanceScore = 0;

    // Getting the booleans out the way first
    if(scored20){
        performanceScore += 25;
    }

    if(shot50FromField){
        performanceScore += 10;
    }
    if(shot40FromThree){
        performanceScore += 15;
    }

    // I decided to do this in ranges, probably a more efficient way of doing this that didn't come to mind

    // FT %
    if(freeThrowPercentage >= 80 && freeThrowPercentage < 90){
        performanceScore += 5;
    }
    else if(freeThrowPercentage >= 90){
        performanceScore +=10;
    }

    // Threes made

    if(threesMade >= 2 && threesMade <= 5){
        performanceScore += 15;
    }

    else if(threesMade >= 6 && threesMade <= 7){
        performanceScore += 20;
    }

    else if(threesMade >= 8 && threesMade < 10){
        performanceScore += 25;
    }

    else if(threesMade >= 10){
        performanceScore += 30;
    }

    // True shooting % using the official formula
    if(trueShooting >= 56 && trueShooting < 60){
        performanceScore +=5;
    }

    else if(trueShooting >= 60 && trueShooting < 65){
        performanceScore += 8;
    }

    else if(trueShooting >= 65 && trueShooting < 70){
        performanceScore +=13;
    }

    else if(trueShooting >= 70 && trueShooting < 75){
        performanceScore +=15;
    }

    // making sure the score isn't over 100
    if(performanceScore > 100){
        performanceScore = 100;
    }

    // I need score level in order to put the scores into ranges and utilize a switch case statement
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
    std::string rating;
    switch(scoreLevel){
        case 0:
            rating = "Poor";
            break;
        case 1:
            rating = "Below Average";
            break;
        case 2:
            rating = "Solid";
            break;
        case 3:
            rating = "Great";
            break;
        case 4:
            rating = "Elite";
            break;
    }
    std::left;
    
    std::cout << "#" << jerseyNumber << ", " << position << ", " << playerName << " played " << rating << ", with a performance score of " << performanceScore;
    std::cout << std::setw(8) << "Points" << std::setw(8) << "FG%" << std::setw(8) << "3PT%" << std::setw(8) << "FT%" << std::setw(8) << "TS%" << std::endl;
    std::cout << std::setw(8) << totalPoints << std::setw(8) << fieldGoalPercentage << std::setw(8) << threePointPercentage << std::setw(8) << freeThrowPercentage << std::setw(8) << trueShooting << std::endl;
    std::cout << (scored20 ? "20+ points!" : "Under 20 points");

    return 0;
}