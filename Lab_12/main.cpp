// Lab 12 Assignment: Barista 
// Gagandeep Dhami
// Professor Bhati  

#include <iostream>
#include <memory>
#include "drink.h"
#include "ingredients.h"

int main() {
    std::cout << "Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? ";
    char sizeInput;
    std::cin >> sizeInput;

    std::shared_ptr<Drink> coffee;
    if (sizeInput == 'l') coffee = std::make_shared<Drink>(DrinkType::large);
    else if (sizeInput == 'm') coffee = std::make_shared<Drink>(DrinkType::medium);
    else coffee = std::make_shared<Drink>(DrinkType::small);

    char ingredientInput;
    do {
        std::cout << "Would you like to add [s]prinkles, [c]aramel, milk [f]oam, [i]ce or [n]ot? ";
        std::cin >> ingredientInput;

        if (ingredientInput == 's') coffee = std::make_shared<Sprinkles>(coffee);
        else if (ingredientInput == 'c') coffee = std::make_shared<Caramel>(coffee);
        else if (ingredientInput == 'f') coffee = std::make_shared<MilkFoam>(coffee);
        else if (ingredientInput == 'i') coffee = std::make_shared<Ice>(coffee);

    } while (ingredientInput != 'n');

    std::cout << "Can I get your name? ";
    std::string name;
    std::cin >> name;

    std::cout << name << ", your " << coffee->getName() << " is ready. It will be $" << coffee->getPrice() / 100.0 << ", please.\n";

    return 0;
}
