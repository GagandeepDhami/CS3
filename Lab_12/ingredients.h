#ifndef INGREDIENTS_H
#define INGREDIENTS_H

#include "ingredient_decorator.h"

class Sprinkles : public IngredientDecorator {
public:
    explicit Sprinkles(std::shared_ptr<Drink> baseDrink) : IngredientDecorator(baseDrink) {}
    
    int getPrice() const override { return baseDrink_->getPrice() + 50; } // $0.50
    std::string getName() const override { return baseDrink_->getName() + " with sprinkles"; }
};

class Caramel : public IngredientDecorator {
public:
    explicit Caramel(std::shared_ptr<Drink> baseDrink) : IngredientDecorator(baseDrink) {}
    
    int getPrice() const override { return baseDrink_->getPrice() + 20; } // $0.20
    std::string getName() const override { return baseDrink_->getName() + " with caramel"; }
};

class MilkFoam : public IngredientDecorator {
public:
    explicit MilkFoam(std::shared_ptr<Drink> baseDrink) : IngredientDecorator(baseDrink) {}
    
    int getPrice() const override { return baseDrink_->getPrice() + 40; } // $0.40
    std::string getName() const override { return baseDrink_->getName() + " with milk foam"; }
};

class Ice : public IngredientDecorator {
public:
    explicit Ice(std::shared_ptr<Drink> baseDrink) : IngredientDecorator(baseDrink) {}
    
    int getPrice() const override { return baseDrink_->getPrice() + 10; } // $0.10
    std::string getName() const override { return baseDrink_->getName() + " with ice"; }
};

#endif // INGREDIENTS_H
