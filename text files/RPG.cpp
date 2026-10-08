// Steven Gonell
// 8.26.26
// RPG battle system
// ?/100

// Libraries
#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <ostream>
#include <iomanip>

// Classes

class Character{
    private:
        std::string name;
        int health;
        int attack;
        bool isAlive;
        int defense;
    public:
        Character(std::string name, int health, int attack, bool isAlive, int defense) : name(name), health(health), attack(attack), isAlive(isAlive), defense(defense){

        }
        std::string getName(){
            return name;
        }
        int getHealth(){
            return health;
        }
        int getAttack(){
            return attack;
        }
        bool getStatus(){
            return isAlive;
        }
        int getDefense(){
            return defense;
        }
        void takeDamage(Character character, int damage){
            if(damage > 0){
                health -=damage;
            }

            if(health <= 0){
                health = 0;
                isAlive = false;
                std::cout << character.getName() << " died!";
            }
        }
        void heal(){
            if(isAlive == false){
                return;
            }
            else{
                health +=25;
            }
            if(health > 100){
                health = 100;
            }
        }
};

class Team{
    private:
        std::string userName;
        std::vector<Character> characters;
    public:
        Team(std::string userName){
            this->userName = userName;
        }
        std::string getUserName(){
            return userName;
        }
};
void attack(Character &attacker, Character &defender){
    if(defender.getStatus() == false){
        std::cerr << "invalid target";
        return;
    }
    int damage = attacker.getAttack() - defender.getDefense();
    if (damage < 0) {
        damage = 0; 
    }
    defender.takeDamage(defender, damage);
}


