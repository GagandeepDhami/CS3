// Gagandeep Dhami
// Professor Bhati
// Lab 01: Diff.
// Aug 22 2024

// Remember, to run program 'clang++ diff.cpp' or './a.out'

#include <iostream>
#include <fstream>
#include <string>

void compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream inFile1(file1);
    std::ifstream inFile2(file2);

    if (!inFile1.is_open() || !inFile2.is_open()) {
        std::cerr << "Error: Unable to open input files." << std::endl;
        return;
    }

    std::string line1, line2;
    int lineNum = 0;

    while (std::getline(inFile1, line1) && std::getline(inFile2, line2)) {
        lineNum++;

        if (line1 != line2) {
            std::cout << file1 << ": " << lineNum << ": " << line1 << std::endl;
            std::cout << file2 << ": " << lineNum << ": " << line2 << std::endl;

            size_t minLength = std::min(line1.length(), line2.length());
            for (size_t i = 0; i < minLength; i++) {
                if (line1[i] != line2[i]) {
                    std::cout << std::string(i, ' ') << '^' << std::endl;
                    break;
                }
            }
        }
    }

    // Handle extra lines in longer file
    while (std::getline(inFile1, line1)) {
        lineNum++;
        std::cout << file1 << ": " << lineNum << ": " << line1 << std::endl;
    }

    while (std::getline(inFile2, line2)) {
        lineNum++;
        std::cout << file2 << ": " << lineNum << ": " << line2 << std::endl;
    }

    inFile1.close();
    inFile2.close();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <file1> <file2>" << std::endl;
        return 1;
    }

    const std::string file1(argv[1]);
    const std::string file2(argv[2]);

    compareFiles(file1, file2);

    return 0;
}
/*

// 1) read in two files, error code of files cant be opened 

// decalaring the files we have to open it up.
std::ifstream file1("file1.txt"); // ifstream: Used to read from files. You would use this class when you want to open a file and read its contents.
std::ifstream file2("file2.txt"); 
std::ifstream file3("file3.txt"); // no file3.txt just want to make sure error message is working 

// error code if file1 cant be opened
if(!file1.is_open() ){            // if (file one is not opened){}
    std::cout << "Error opening up 'file1.txt' " << std::endl;
}

// error code if file2 cant be opened
if(!file2.is_open() ){
    std::cout << "Error opening up 'file2.txt' " << std::endl;
}

/* test code for file not in system. 
if(!file3.is_open() ){
    std::cout << "Error opening up 'file3.txt' " << std::endl;
}

}
*/