// testing the implementation of templated list collection
// Joseph Oglio
// 12/20/2023

//Lab 3

#include <iostream>
#include <string>
#include <cassert>
#include "collection.h" // template definition
#include "list.h" // list template
using namespace std;

int main() {
    // Manipulating integers
    Collection<int> cone; // Specify the type for the template
    cout << "Integer collection: ";
    cone.addItem(1);
    cone.addItem(2);
    cone.addItem(3);
    cone.printCollection();
    cone.removeItem(2);
    cone.printCollection();

    // Manipulating strings
    string sa[] = { "yellow", "orange", "green", "blue" }; // Correct declaration
    Collection<string> ctwo; // Specify the type for the template
    for (auto& s : sa) { // Use reference to avoid unnecessary copies
        ctwo.addItem(s);
    }
    cout << "String collection: ";
    ctwo.printCollection();

    // Manipulating character collections
    Collection<char> a2g, h2n, o2u; // Specify the type for the template
    for (char c = 'a'; c <= 'g'; ++c) {
        a2g.addItem(c);
    }
    for (char c = 'h'; c <= 'n'; ++c) {
        h2n.addItem(c);
    }
    for (char c = 'o'; c <= 'u'; ++c) {
        o2u.addItem(c);
    }

    // Collection of collections
    Collection<Collection<char> > cpile; // Nested collections
    cpile.addItem(a2g);
    cpile.addItem(h2n);
    cpile.addItem(o2u);

    // Printing characters from the last collection added
    cout << "Last added character collection: ";
    cpile.lastItem().printCollection();

    return 0;
}
    // uncomment when you debugged the code above
    /*

    // manipulating strings
    string sa[] = {"yellow", "orange", "green", "blue"};
    Collection<string> ctwo;

    cout << "adding an array of strings ";
    for(auto s : sa)
    ctwo.add(s);

    cout << "String collection: ";
    ctwo.print();


    // manipulating character collections

    // individal collections
    Collection<char> a2g, h2n, o2u;
    cout << "Populating individual character collections" << endl;
    for(char c='a'; c <='g'; ++c) {
    a2g.add(c);
    assert(a2g.last() == c);
    }
    for(char c='h'; c <='n'; ++c) h2n.add(c);
    for(char c='o'; c <='u'; ++c) o2u.add(c);


    assert(!equal(a2g, h2n));

    // collection of collections
    Collection<Collection<char>> cpile;

    cout << "Adding individual collections " << endl;
    cpile.add(a2g);
    assert(equal(cpile.last(), a2g));
    cpile.add(h2n);
    assert(equal(cpile.last(), h2n));
    cpile.add(o2u);
    assert(equal(cpile.last(), o2u));

    // printing characters from last collection added
    cout << "Last added character collection: ";
    cpile.last().print();
    */
