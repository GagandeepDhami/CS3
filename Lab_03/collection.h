// Lab 3 Assignmnet: Templated List
// Gagandeep Dhami
// Professor Bhati 

#ifndef COLLECTION_H_
#define COLLECTION_H_

#include "list.h"   // Includes the custom list implementation
#include <iostream> // For standard input/output operations

// Templated Collection class
template <typename T> 
class Collection {
public:
    // Constructor: Initializes the head and tail pointers to nullptr, indicating an empty collection.
    Collection() : head_(nullptr), tail_(nullptr) {} 

    // Add an item to the collection
    void addItem(const T& item) {
        node<T>* newNode = new node<T>();      // Creates a new node of type T
        newNode->setData(item);                // Sets the data of the new node to the provided item
        newNode->setNext(nullptr);             // Ensures the new node points to nothing (end of the list)

        if (tail_) {                           // If the collection already has a tail (not empty):
            tail_->setNext(newNode);           // Link the current tail to the new node
        } else {                               // If the collection is empty:
            head_ = newNode;                   // Set the head to the new node
        }
        tail_ = newNode;                       // Update the tail pointer to the new node
    }

    // Remove all instances of the specified item
    void removeItem(const T& item) {
        node<T>* current = head_;              // Starts traversing from the head of the list
        node<T>* previous = nullptr;           // Keeps track of the previous node for linking

        while (current) {                      // Traverse the list until the end
            if (current->getData() == item) {  // If the current node contains the item to remove:
                if (current == head_) {        // Special case: if the node is the head:
                    head_ = head_->getNext();  // Update the head to the next node
                } else {                       // For non-head nodes:
                    previous->setNext(current->getNext()); // Link previous node to the next node
                }
                if (current == tail_) {        // Special case: if the node is the tail:
                    tail_ = previous;          // Update the tail to the previous node
                }
                node<T>* toDelete = current;   // Save the current node to delete
                current = current->getNext();  // Move to the next node
                delete toDelete;               // Delete the saved node
            } else {                           // If the current node does not contain the item:
                previous = current;            // Move the previous pointer forward
                current = current->getNext();  // Move the current pointer forward
            }
        }
    }

    // Return the last item added to the collection
    T lastItem() const {
        if (tail_) {                           // If the tail exists:
            return tail_->getData();           // Return the data of the tail node
        }
        throw std::runtime_error("Collection is empty!"); 
    }

    // Print all items in the collection
    void printCollection() const {
        node<T>* current = head_;             // Starts traversing from the head of the list
        while (current) {                     // Traverse the list until the end
            std::cout << current->getData() << " "; // Print the data of each node
            current = current->getNext();     // Move to the next node
        }
        std::cout << std::endl;               // End the line after printing all items
    }

    ~Collection() {                           // Destructor: Ensures proper cleanup of dynamically allocated memory
        node<T>* current = head_;             // Starts traversing from the head of the list
        while (current) {                     // Traverse the list until all nodes are deleted
            node<T>* toDelete = current;      // Save the current node to delete
            current = current->getNext();     // Move to the next node
            delete toDelete;                  // Delete the saved node
        }
    }

private:
    node<T>* head_;                           // Pointer to the first node in the list
    node<T>* tail_;                           // Pointer to the last node in the list
};

#endif // COLLECTION_H_
