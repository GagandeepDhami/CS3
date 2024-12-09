// Lab 10 Assignment: Bridge Painted Square
// Gagandeep Dhami
// Professor Bhati  

#include <iostream>
#include <vector>

// Base class Fill
class Fill {
protected:
    char borderPaint;
    char internalPaint;

public:
    // Constructor accepting two characters for border and internal paints
    Fill(char border, char internal) : borderPaint(border), internalPaint(internal) {}

    virtual ~Fill() {}

    // Virtual function to display the square
    virtual void displaySquare(int size) const = 0;
};

// Derived class Hollow
class Hollow : public Fill {
public:
    Hollow(char border) : Fill(border, ' ') {}          // Border character and space for internal paint

    void displaySquare(int size) const override {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                    std::cout << borderPaint;
                else
                    std::cout << internalPaint;
            }
            std::cout << std::endl;
        }
    }
};

// Derived class Filled
class Filled : public Fill {
public:
    Filled(char paint) : Fill(paint, paint) {}          // Both border and internal paint are the same

    void displaySquare(int size) const override {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << borderPaint;
            }
            std::cout << std::endl;
        }
    }
};

// Derived class EnhancedFilled
class EnhancedFilled : public Filled {
public:
    EnhancedFilled(char border, char internal) : Filled(border) {
        this->internalPaint = internal;                 // Allow different internal and border paint
    }

    void displaySquare(int size) const override {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                    std::cout << borderPaint;
                else
                    std::cout << internalPaint;
            }
            std::cout << std::endl;
        }
    }
};

// Function to demonstrate the operation of all three paint classes
void demonstratePaintClasses() {
    int squareSize = 5;                                  // Example size of the square

    std::cout << "Hollow Square:" << std::endl;
    Hollow hollowSquare('#');
    hollowSquare.displaySquare(squareSize);

    std::cout << "\nFilled Square:" << std::endl;
    Filled filledSquare('*');
    filledSquare.displaySquare(squareSize);

    std::cout << "\nEnhanced Filled Square:" << std::endl;
    EnhancedFilled enhancedFilledSquare('@', '+');
    enhancedFilledSquare.displaySquare(squareSize);
}

// Main function
int main() {
    demonstratePaintClasses();
    return 0;
}
