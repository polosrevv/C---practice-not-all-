// Steven Gonell
// 8/07/2026
// Counting animals to learn more about binary and how memory works and how its stored

#include <iostream>

// Variables to store animal counts
int elephant_count;

int lion_count{};

int dog_count {10};

int cat_count {15};

int main() {
    // Variables to store animal category counts + total
    int domesticated_animals = dog_count + cat_count;
    int wild_animals = elephant_count + lion_count;
    int total_animals = domesticated_animals + wild_animals;


    //Display the results

    std::cout << "Domesticated animals: " << domesticated_animals << std::endl;
    std::cout << "Wild animals: " << wild_animals << std:: endl;
    std::cout << "Total animals: " << total_animals << std::endl;
    std::cout << "Size of elephant_count: " << sizeof(elephant_count) << " bytes" << std::endl;
    std::cout << "Size of lion_count: " << sizeof(lion_count) << " bytes" << std::endl;
    std::cout << "Size of dog_count: " << sizeof(dog_count) << " bytes" << std::endl;
    std::cout << "Size of cat_count: " << sizeof(cat_count) << " bytes" << std::endl;
    return 0;
}