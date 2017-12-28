// Author: Jake Edwards
// Professor: Dr. Ivancic
// Class: CSC 331-001
// Date: 10/24/2017
// Assignment: Homework 4

#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;

int main(int argc, char* argv[]) {

    ifstream input("p4.dat");
    int numLines = 0;
    string tempString;
    while (!input.eof()) { // This will go through the whole file and count how many lines there are
        getline(input, tempString);
        numLines++;
    }

    input.clear();
    input.seekg(0, ios::beg);

    Dictionary dictionary(numLines);

    // now load the dictionary from the file
    string isbn;
    string title;
    while (!input.eof()) {
        input >> isbn;
        getline(input, title);

        keypair book = {
            isbn, title
        };

        dictionary.addPair(book);
    }

    bool keepRunning = true; // will become false when user enters exit
    string userInput;
    while (keepRunning) {
        cout << "Enter an ISBN number to search for a book or type \"exit\" to leave the program" << endl;
        cin >> userInput;

        if (userInput == "exit") { // user enters exit
            keepRunning = false;
        }
        else { // user enters an isbn to search for a title
            string searchTitle = dictionary.searchIndex(userInput);
            cout << searchTitle.string::substr(1, searchTitle.length()) << endl;
        }
    }




    return 0;
}
