// Lab 9 Assignment: Dice Game
// Gagandeep Dhami
// Professor Bhati  

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Base Game class (not provided in the question, so assuming structure)
class Game {
protected:
    int playersCount_;
    int movesCount_ = 0;
    int playerWon_ = -1;

public:
    virtual void initializeGame() = 0;
    virtual void makeMove(int player) = 0;
    virtual void printWinner() = 0;

    void playGame() {
        initializeGame();
        while (movesCount_ < 3) {                       // Maximum of 3 rounds
            for (int i = 0; i < playersCount_; i++) {
                makeMove(i);
            }
            movesCount_++;
        }
        printWinner();
    }
};

// Derived Dice class
class Dice : public Game {
private:
    static const int numPlayers_ = 2;
    static const int maxMoves_ = 3;
    static const int numDice_ = 5;
    int roll_[numDice_];
    int highRoll_[numPlayers_];
    char reRoll_[numPlayers_];
    string players[numPlayers_];

public:
    void initializeGame() override {
        playersCount_ = numPlayers_;
        movesCount_ = 0;
        for (int i = 0; i < numPlayers_; i++) {
            reRoll_[i] = 'y';
            highRoll_[i] = 0;
        }
        players[0] = "Computer";
        players[1] = "You";
    }

    void makeMove(int player) override {
        if (reRoll_[player] == 'y') {
            int sum = 0;
            cout << players[player] << " rolled: ";
            for (int i = 0; i < numDice_; i++) {
                roll_[i] = rand() % 6 + 1;
                sum += roll_[i];
                cout << roll_[i] << " ";
            }
            cout << "= " << sum << ", " << players[player] << "'s highest score = ";

            // Update the player's highest score if the new roll is higher
            if (sum > highRoll_[player]) {
                highRoll_[player] = sum;
            }
            cout << highRoll_[player] << endl;
        } else {
            cout << players[player] << " passed, highest score = " << highRoll_[player] << endl;
        }

        if (player == 0) { // Computer logic
            if (reRoll_[player] == 'y') {
                reRoll_[player] = (rand() % 2 == 0) ? 'y' : 'n';
            }
        } else { // Human logic
            if (reRoll_[player] == 'y') {
                cout << "Roll again? [y/n] ";
                cin >> reRoll_[player];
            }
        }
    }

    void printWinner() override {
        cout << "Final Scores:\n";
        cout << "Computer: " << highRoll_[0] << "\n";
        cout << "You: " << highRoll_[1] << "\n";
        if (highRoll_[1] > highRoll_[0]) {
            cout << "You Win!\n";
        } else {
            cout << "You Lose!\n";
        }
    }
};

// Main function to run the game
int main() {
    srand(static_cast<unsigned>(time(0)));             // Seed random number generator
    Dice diceGame;
    diceGame.playGame();
    return 0;
}
