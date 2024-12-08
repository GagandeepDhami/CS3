#ifndef COLLECTION_H_
#define COLLECTION_H_

#include "list.h"
#include <iostream>

// Templated Collection class
template <typename T>
class Collection {
public:
    Collection() : head_(nullptr), tail_(nullptr) {}

    // Add an item to the collection
    void addItem(const T& item) {
        node<T>* newNode = new node<T>();
        newNode->setData(item);
        newNode->setNext(nullptr);

        if (tail_) {
            tail_->setNext(newNode);
        }
        else {
            head_ = newNode;
        }
        tail_ = newNode;
    }

    // Remove all instances of the specified item
    void removeItem(const T& item) {
        node<T>* current = head_;
        node<T>* previous = nullptr;

        while (current) {
            if (current->getData() == item) {
                if (current == head_) {
                    head_ = head_->getNext();
                }
                else {
                    previous->setNext(current->getNext());
                }
                if (current == tail_) {
                    tail_ = previous;
                }
                node<T>* toDelete = current;
                current = current->getNext();
                delete toDelete;
            }
            else {
                previous = current;
                current = current->getNext();
            }
        }
    }

    // Return the last item added to the collection
    T lastItem() const {
        if (tail_) {
            return tail_->getData();
        }
        throw std::runtime_error("Collection is empty!");
    }

    // Print all items in the collection
    void printCollection() const {
        node<T>* current = head_;
        while (current) {
            std::cout << current->getData() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }

    ~Collection() {
        node<T>* current = head_;
        while (current) {
            node<T>* toDelete = current;
            current = current->getNext();
            delete toDelete;
        }
    }

private:
    node<T>* head_;
    node<T>* tail_;
};

#endif // COLLECTION_H_
