#ifndef INGREDIENT_DECORATOR_H
#define INGREDIENT_DECORATOR_H

#include "drink.h"
#include <memory>

class IngredientDecorator : public Drink {
public:
    explicit IngredientDecorator(std::shared_ptr<Drink> baseDrink)
        : Drink(baseDrink->getType()), baseDrink_(baseDrink) {}

    int getPrice() const override { return baseDrink_->getPrice(); }
    std::string getName() const override { return baseDrink_->getName(); }

protected:
    std::shared_ptr<Drink> baseDrink_;
};

#endif // INGREDIENT_DECORATOR_H
