#include <iostream>
#include <string>
#include <vector>

class item{
    private:
        std::string name;
        int value;
    public:
        item(std::string name,int value) : name(name), value(value){

        } 
        std::string getName(){
            return name;
        }
        int getValue(){
            return value;
        }
};

class inventory{
    private:
        std::vector<item> items;
    public:
        inventory(){

        }
        void addItem(item object){
            items.push_back(object);
        }
        void printItems(){
            std::cout << "============== Items ==============" << std::endl;
            if(items.size() == 0){
                std::cerr << "No items in inventory";
            }
            else{
                int count = 1;
                for(item i : items){
                std::cout << "Slot " << count << " " << i.getName() << " " << i.getValue() << std::endl;
                count++;
            }
        }
        
            
    }
    void deleteItem(){
        std::string removedItem;
        std::cout << "Which item do you want to remove from your inventory: ";
        std:: cin >> removedItem;
        std::cout << std::endl;
        for(int i= 0; i<items.size();i++){
            if(items[i].getName() == removedItem){
                items.erase(items.begin() + i);
                break;
            }
        }
        }
    void findItem(){
        std::string itemToFind;
        bool found = false;
        std::cout << "Which item are you looking for: ";
        std::cin >> itemToFind;
        std::cout << std::endl;
        for(int i = 0; i< items.size(); i++){
            if(items[i].getName() == itemToFind){
                std::cout << "Item found at: " << i;
                found = true;
                break;
            }
            
        }
        if(found == false){
                std::cout << "Item not found:(";
            }
    }
    bool itemExists(std::string itemFind){
        for(int i = 0; i< items.size();i++){
            if(items[i].getName() == itemFind){
                return true;
            }
        }
        return false;
    }
};

int main(){
    item item1("Health Potion", 50);
    item item2("Iron Sword", 150);
    item item3("Shield", 100);
    inventory inventory1;
    inventory1.addItem(item1);
    inventory1.addItem(item2);
    inventory1.addItem(item3);
    std::cout << item1.getName() << " " << item1.getValue() << std::endl;
    std::cout << item2.getName() << " " << item2.getValue() << std::endl;
    std::cout << item3.getName() << " " << item3.getValue() << std::endl;
    inventory1.printItems();
    inventory1.deleteItem();
    inventory1.printItems();
    std::cout << inventory1.itemExists("Shield");
}