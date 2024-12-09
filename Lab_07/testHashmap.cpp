// demoes hashmap implementation
// Wayne Cheng
// 4/10/2018

#include "hashmap.h"
#include <iostream>
#include <string>

using std::cin; 
using std::cout; 
using std::endl;
using std::string;

int main() {
    hashmap<int, int> myHash;

    // Test insert()
    auto result = myHash.insert({1, 10});
    cout << "Insert 1: " << (result.second ? "Success" : "Failure") 
         << ", Value: " << result.first->second << endl;

    result = myHash.insert({1, 20});
    cout << "Insert duplicate 1: " << (result.second ? "Success" : "Failure") 
         << ", Value: " << result.first->second << endl;

    // Test operator[]
    cout << "Value for key 2: " << myHash[2] << endl;
    myHash[2] = 30;
    cout << "Updated value for key 2: " << myHash[2] << endl;

    // Test erase()
    auto eraseResult = myHash.erase(1);
    cout << "Erase key 1: " << (eraseResult.second ? "Success" : "Failure") << endl;

    eraseResult = myHash.erase(3);
    cout << "Erase non-existent key 3: " << (eraseResult.second ? "Success" : "Failure") << endl;

    // Test rehash()
    myHash.rehash(200);
    cout << "Rehashed to 200 buckets successfully." << endl;

    return 0;
}
