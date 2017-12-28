#include <iostream>
#include "Dictionary.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

Dictionary::Dictionary() {
    this->book = new keypair[10];
    this->size = 0;
    this->capacity = 10;
}

Dictionary::Dictionary(int capacity) {
    this->book = new keypair[capacity];
    this->size = 0;
    this->capacity = capacity;
}

Dictionary::Dictionary(keypair kp, int capacity) {
    this->book = new keypair[capacity];
    this->size = 1;
    this->capacity = capacity;
    book[0] = kp;
}

Dictionary::~Dictionary() {
    delete[] book;
}

void Dictionary::addPair(keypair kp) {
    if (size < capacity) {
        book[size] = kp;
        size++;
    }
    else {
        cout << "Dictionary is full, cannot add." << endl;
    }
}

void Dictionary::removePairOnIndex(string isbn) {

    bool notFound = true;
    int counter = 0;
    while (notFound && counter < capacity) {
        if (book[counter].index == isbn) {
            book[counter].index = "0";
            book[counter].value = "0";
            size--;
            notFound = false;
        }
        else {
            counter++;
        }
    }

    if (notFound) {
        cout << "That book was not found" << endl;
    }
}

string Dictionary::searchIndex(string isbn) {
    bool notFound = true;
    int counter = 0;
    while (counter < capacity) {
        if (book[counter].index == isbn) {
            return book[counter].value;
            notFound = false;
            break;
        }
        else {
            counter++;
        }
    }

    if (notFound) {
        cout << "That book was not found" << endl;
    }
}

void Dictionary::printContents() {
    if (size == 0) { //dictionary is empty
        cout << "Dictionary is empty" << endl;
    }
    else {

        cout << "ISBN       " << "Book Title" << endl << endl;

        for(int i = 0; i <= size; i++) {
            cout << book[i].index << " " << book[i].value << endl;
        }
    }

}
