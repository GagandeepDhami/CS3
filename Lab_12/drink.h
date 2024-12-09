#ifndef DRINK_H
#define DRINK_H

#include <string>

enum class DrinkType { small, medium, large };

class Drink {
public:
    explicit Drink(DrinkType type) : type_(type), price_(calculateBasePrice(type)) {}
    virtual ~Drink() = default;

    virtual int getPrice() const { return price_; }
    virtual std::string getName() const {
        switch (type_) {
            case DrinkType::small: return "small coffee";
            case DrinkType::medium: return "medium coffee";
            case DrinkType::large: return "large coffee";
        }
        return "unknown coffee";
    }

    DrinkType getType() const { return type_; } // Add this method to expose the type

protected:
    DrinkType type_;
    int price_;

private:
    static int calculateBasePrice(DrinkType type) {
        switch (type) {
            case DrinkType::small: return 100;  // $1.00
            case DrinkType::medium: return 200; // $2.00
            case DrinkType::large: return 300;  // $3.00
        }
        return 0; // Default case
    }
};

#endif // DRINK_H

