// Gagandeep Dhami
// Professor Bhati
// Lab 01: Diff.
// Aug 22 2024

// Remember, to run program 'clang++ diff.cpp' or './a.out'

#include <iostream>
#include <string>
#include <fstream> // needed for file operations 

int main(){

// 1) read in two files, erroe code of files cant be opened 

// decalsring the files we have to open it up.
std::ifstream file1("file1.txt"); // ifstream: Used to read from files. You would use this class when you want to open a file and read its contents.
std::ifstream file2("file2.txt"); 
std::ifstream file3("file3.txt"); // no file3.txt just want to make sure error message is working 

// error code if file1 cant be opened
if(!file1.is_open() ){            // if (file one is not opened){}
    std::cout << "Error opening up 'file1.txt' " << std::endl;
}

// error code if file1 cant be opened
if(!file2.is_open() ){
    std::cout << "Error opening up 'file2.txt' " << std::endl;
}

/* test code for file not in system. 
if(!file3.is_open() ){
    std::cout << "Error opening up 'file3.txt' " << std::endl;
}
*/

}
