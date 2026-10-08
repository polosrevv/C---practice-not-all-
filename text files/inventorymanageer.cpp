#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct item {
    std::string name;
    std::string category;
    int quantity;
    float price;
};

void addItem(std::vector<item>& items) {
    item newItem;
    std::cout << "Name: ";
    std::cin >> newItem.name;
    std::cout << "Category: ";
    std::cin >> newItem.category;
    std::cout << "Quantity: ";
    std::cin >> newItem.quantity;
    std::cout << "Price: ";
    std::cin >> newItem.price;
    std::cout << std::endl;
    items.push_back(newItem);
}

void viewInventory(const std::vector<item>& items) {
    std::cout << "\n--- INVENTORY ---" << std::endl;
    std::cout << std::left << std::setw(15) << "Name" 
    << std::setw(15) << "Category" 
    << std::setw(10) << "Quantity" 
    << std::setw(10) << "Price" << std::endl;
    std::cout << "---------------------------------------------–------" << std::endl;
    
    for (const item& i : items) {
        std::cout << std::left << std::setw(15) << i.name 
        << std::setw(15) << i.category 
        << std::setw(10) << i.quantity 
        << std::setw(10) << std::fixed << std::setprecision(2) << i.price << std::endl;
    }
    std::cout << std::endl;
}

void searchForItem(const std::vector<item>& items) {
    std::string lookingFor;
    std::cout << "Which item are you looking for (name): ";
    std::cin >> lookingFor;
    std::cout << std::endl;
    
    bool found = false;
    for (const item& i : items) {
        if (i.name == lookingFor) {
            std::cout << "Found item: " << i.name 
            << " | Category: " << i.category 
            << " | Qty: " << i.quantity 
            << " | Price: $" << i.price << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Item not found." << std::endl;
    }
}

void removeItem(std::vector<item>& items) {
    std::string removedItem;
    std::cout << "Which item would you like to remove (name): ";
    std::cin >> removedItem;
    bool removed = false;
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == removedItem) {
            items.erase(it);
            std::cout << "Item '" << removedItem << "' removed successfully." << std::endl;
            removed = true;
            break; 
        }
    }
    if (!removed) {
        std::cout << "Item not found in inventory." << std::endl;
    }
}

void calculateInventoryValue(const std::vector<item>& items) {
    float sum = 0;
    for (const item& i : items) {
        sum += static_cast<float>(i.quantity) * i.price; 
    }
    std::cout << "Total value of your inventory: $" << std::fixed << std::setprecision(2) << sum << std::endl;
}

void showMostAndLeastExpensive(const std::vector<item>& items) {
    if (items.empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }


    float max = items[0].price;
    float min = items[0].price;
    std::string maxName = items[0].name;
    std::string minName = items[0].name;

    for (const item& i : items) {
        if (i.price < min) {
            min = i.price;
            minName = i.name;
        }
        if (i.price > max) {
            max = i.price;
            maxName = i.name;
        }
    }

    std::cout << "\n" << std::left << std::setw(15) << "Type" << std::setw(15) << "Name" << std::setw(10) << "Price" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "Highest:" << std::setw(15) << maxName << "$" << max << std::endl;
    std::cout << std::left << std::setw(15) << "Lowest:" << std::setw(15) << minName << "$" << min << std::endl;
}

int main() {
    std::vector<item> items;
    bool exit = false;

    while (!exit) {
        int option = 0;
        std::cout << "\n--- INVENTORY MANAGER ---" << std::endl;
        std::cout << "1. Add item" << std::endl;
        std::cout << "2. View inventory" << std::endl;
        std::cout << "3. Search for item" << std::endl;
        std::cout << "4. Remove item" << std::endl;
        std::cout << "5. Calculate inventory value" << std::endl;
        std::cout << "6. Show most / least expensive item" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option) {
            case 1: 
                addItem(items); 
                break;
            case 2: 
                viewInventory(items); 
                break;
            case 3: 
                searchForItem(items); 
                break;
            case 4: 
                removeItem(items); 
                break;
            case 5: 
                calculateInventoryValue(items); 
                break;
            case 6: 
                showMostAndLeastExpensive(items); 
                break;
            case 7: 
                exit = true; 
                break;
            default: 
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    }
    return 0;
}
