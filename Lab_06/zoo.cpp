// Lab 6 Assignment: Zoo Audit
// Gagandeep Dhami
// Professor Bhati  

#include <iostream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

// Typedefs for readability
using EnclosurePair = pair<string, list<string>>;                                  // Alias for a pair of enclosure name and animal list
using ZooMap = map<string, list<string>>;                                          // Alias for a map of enclosure name to animal list

// Function declarations
void auditEnclosures(ZooMap& animalsByEnclosure, const list<string>& sickAnimals); // Audit enclosures
multiset<string> getDuplicates(const ZooMap& animalsByEnclosure);                  // Get duplicate animals

int main() {
    // Initialize ZooMap with enclosures and animals
    ZooMap animals = {
        { "Orange", { "aardvark", "lion", "buffalo", "wildcat", "lion", "eagle" } },
        { "Green", { "elephant", "zebra", "aardvark", "bear", "alligator" } },
        { "Yellow", { "goose", "alligator", "flamingo", "goose" } },
        { "Blue", { "shark", "dolphin", "alligator", "turtle", "eagle", "penguin" } },
        { "Red", { "deer", "duck", "wildcat", "lion" } }
    };

    list<string> sickAnimals = { "buffalo", "wildcat", "eagle" };                 // List of sick animals

    // Lambda to print an enclosure and its animals
    auto printEnclosure = [](const EnclosurePair& enclosure) {
        cout << enclosure.first << ":";                                           // Print enclosure name
        for (const auto& str : enclosure.second) {                                // Print each animal
            cout << ' ' << str;
        }
        cout << endl;
    };

    // Print enclosures before audit
    cout << "Before audit:" << endl;
    for_each(animals.cbegin(), animals.cend(), printEnclosure);
    cout << endl;

    // Perform the audit to remove duplicates and sick animals
    auditEnclosures(animals, sickAnimals);

    // Print enclosures after audit
    cout << "After audit:" << endl;
    for_each(animals.cbegin(), animals.cend(), printEnclosure);
    cout << endl;

    return 0;
}

// Function to audit enclosures and remove duplicates and sick animals
void auditEnclosures(ZooMap& animalsByEnclosure, const list<string>& sickAnimals) {
    // Get duplicate animals as a multiset
    multiset<string> toRemove = getDuplicates(animalsByEnclosure);

    // Add sick animals to the removal list
    for (const auto& sick : sickAnimals) {
        toRemove.insert(sick);                                                   // Sick animals are removed from all enclosures
    }

    // Remove duplicates and sick animals from enclosures
    for_each(animalsByEnclosure.begin(), animalsByEnclosure.end(), [&toRemove](std::pair<const std::string, std::list<std::string>>& enclosure) {
        auto it = remove_if(enclosure.second.begin(), enclosure.second.end(), [&toRemove](const std::string& name) {
            // Check if the animal is in the removal list
            auto duplicateIt = toRemove.find(name);
            if (duplicateIt != toRemove.end()) {                                // If found, remove it
                toRemove.erase(duplicateIt);                                    // Decrement the count of the animal in the multiset
                return true;                                                    // Remove the animal
            }
            return false;                                                       // Keep the animal
        });
        enclosure.second.erase(it, enclosure.second.end());                     // Remove animals marked for removal
    });
}

// Function to get duplicate animals as a multiset
multiset<string> getDuplicates(const ZooMap& animalsByEnclosure) {
    list<string> allNames;                                                      // List to collect all animal names across enclosures

    // Gather all animal names into a single list
    for (const auto& enclosure : animalsByEnclosure) {
        allNames.insert(allNames.end(), enclosure.second.begin(), enclosure.second.end());
    }

    unordered_map<string, int> animalCount;                                     // Map to count occurrences of each animal
    for (const auto& name : allNames) {
        animalCount[name]++;                                                    // Increment the count for each animal
    }

    multiset<string> duplicates;                                                // Multiset to store duplicates
    for (const auto& pair : animalCount) {                                      // Iterate over the animal count map
        const string& name = pair.first;
        int count = pair.second;
        if (count > 1) {                                                        // If the animal appears more than once
            for (int i = 0; i < count - 1; ++i) {                               // Add (count - 1) instances of the animal
                duplicates.insert(name);
            }
        }
    }

    return duplicates;                                                          // Return the multiset of duplicates
}


