// Lab 9 Assignment: Abstract Car Dealership
// Gagandeep Dhami
// Professor Bhati  

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Helper function for case-insensitive comparison
string toLower(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

// Abstract Car class
class Car {
public:
    virtual string getMake() const = 0;
    virtual string getModel() const = 0;
    virtual ~Car() {}
};

// Concrete Car classes
class Sedan : public Car {
public:
    string getMake() const override { return "Sedan"; }
    string getModel() const override { return "Basic"; }
};

class SUV : public Car {
public:
    string getMake() const override { return "SUV"; }
    string getModel() const override { return "Advanced"; }
};

// Abstract Factory class
class CarFactory {
public:
    virtual Car* createCar() = 0;
    virtual ~CarFactory() {}
};

// Concrete Factories
class SedanFactory : public CarFactory {
public:
    Car* createCar() override {
        if (rand() % 2 == 0) {
            return new Sedan();
        } else {
            return new SUV();                         // Add variation for testing
        }
    }
};

class SUVFactory : public CarFactory {
public:
    Car* createCar() override {
        if (rand() % 2 == 0) {
            return new SUV();
        } else {
            return new Sedan();                       // Add variation for testing
        }
    }
};

// Car Lot class
class CarLot {
private:
    vector<Car*> lot;
    static const int maxLotSize = 10;

public:
    ~CarLot() {
        for (Car* car : lot)
            delete car;
    }

    bool lotFull() const {
        return lot.size() >= maxLotSize;
    }

    void startOver() {
        cout << "Clearing the lot to make space for new cars...\n";
        for (Car* car : lot) {
            delete car;
        }
        lot.clear();
    }

    void nextCar(Car* car) {
        if (lotFull()) {
            cout << "The lot is full! Can't add more cars.\n";
            delete car;
            return;
        }

        for (const Car* c : lot) {
            if (c->getMake() == car->getMake() && c->getModel() == car->getModel()) {
                delete car; // Avoid duplicates
                return;
            }
        }

        lot.push_back(car);
    }

    Car* testDrive(const string& desiredMake, const string& desiredModel) {
        for (size_t i = 0; i < lot.size(); ++i) {
            if (toLower(lot[i]->getMake()) == toLower(desiredMake) && toLower(lot[i]->getModel()) == toLower(desiredModel)) {
                cout << "Found your desired car: " << lot[i]->getMake() << " " << lot[i]->getModel() << ". Buying it!\n";
                Car* purchasedCar = lot[i];
                lot.erase(lot.begin() + i);                // Remove from lot
                return purchasedCar;
            }
        }
        cout << "Desired car not found. Keep searching...\n";
        return nullptr;
    }

    void displayLot() const {
        cout << "Current cars in the lot:\n";
        for (const Car* car : lot) {
            cout << "- " << car->getMake() << " " << car->getModel() << "\n";
        }
    }
};

// Buyer function
void carBuyer(CarLot& carLot, CarFactory* factories[], int factoryCount) {
    string desiredMake, desiredModel;

    cout << "Enter your desired car make (e.g., Sedan, SUV): ";
    cin >> desiredMake;
    cout << "Enter your desired car model (e.g., Basic, Advanced): ";
    cin >> desiredModel;

    carLot.startOver();                                      // Reset the lot
    while (!carLot.lotFull()) {
        carLot.displayLot();

        Car* purchasedCar = carLot.testDrive(desiredMake, desiredModel);
        if (purchasedCar) {
            delete purchasedCar;                             // Assume the buyer owns it and is happy
            return;
        }

        // Add a new random car to the lot
        CarFactory* factory = factories[rand() % factoryCount];
        carLot.nextCar(factory->createCar());
    }

    cout << "Lot is full, and your desired car was not found. Buyer leaves.\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));                  // Seed for randomness

    CarFactory* factories[] = {new SedanFactory(), new SUVFactory()};
    int factoryCount = sizeof(factories) / sizeof(factories[0]);

    CarLot carLot;
    carBuyer(carLot, factories, factoryCount);

    for (CarFactory* factory : factories)
        delete factory;

    return 0;
}

