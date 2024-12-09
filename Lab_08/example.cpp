// Lab 8 Assignment: Singleton Logger
// Gagandeep Dhami
// Professor Bhati  

#include <iostream>   // For standard I/O operations
#include <fstream>    // For file handling
#include <string>     // For std::string class

// Logger class implementing the Singleton pattern
class Logger {
public:
    // Static method to get the single instance of Logger (Meyers Singleton)
    static Logger& getInstance() {
        static Logger instance;                                      // Ensures a single instance is created
        return instance;
    }

    // Method to append a message to the log file
    void report(const std::string& message) {
        // Open the log file if it is not already open
        if (!logFile.is_open()) {
            logFile.open("log.txt", std::ios::out | std::ios::app); // Open in append mode
            if (!logFile) {                                         // Check if the file was opened successfully
                std::cerr << "Error opening log file!" << std::endl;
                return;
            }
        }
        logFile << message << std::endl;                            // Write the message to the log file
    }

private:
    std::ofstream logFile;                                         // File stream for managing the log file

    // Private constructor to prevent multiple instances
    Logger() {}
    
    // Destructor to ensure the file is closed properly
    ~Logger() {
        if (logFile.is_open()) {
            logFile.flush();                                       // Flush any remaining data to the file
            logFile.close();                                       // Close the file
        } 
    }

    // Delete the copy constructor to prevent copying of the singleton
    Logger(const Logger&) = delete;

    // Delete the assignment operator to prevent assignment of the singleton
    Logger& operator=(const Logger&) = delete;
};

// Function for interactive logging
void interactiveLogging() {
    Logger& logger = Logger::getInstance();                        // Get the Logger instance
    std::string userInput;                                         // Variable to store user input

    // Prompt the user to enter messages
    std::cout << "Enter messages to log (type 'exit' to quit):" << std::endl;

    // Loop to accept user input and log it
    while (true) {
        std::getline(std::cin, userInput);                         // Read input from the user
        if (userInput == "exit") {                                 // Check for the exit command
            std::cout << "Exiting the logger." << std::endl;
            break;                                                 // Exit the loop
        }
        logger.report(userInput);                                  // Log the user input to the file
        std::cout << "Logged: " << userInput << std::endl;         // Confirm the log
    }
}

// Main function
int main() {
    interactiveLogging();                                          // Call the interactive logging function
    return 0;                                                      // Exit the program
}

