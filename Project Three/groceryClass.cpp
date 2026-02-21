/*
 * Jorge Chavarria
 * CS 210 Project Three - Corner Grocer Item Tracker (Class Implementation)
 *
 * Grocery class handles:
 *  - Displaying the menu
 *  - Opening input/output files safely
 *  - Reading the input file into an ordered map<string,int>
 *  - Writing the backup file frequency.dat
 *  - Printing item frequencies and histogram output
 */

#include "grocery.h"

void Grocery::displayMenu() {
    cout << "======================================" << endl;
    cout << "        Corner Grocer - Menu          " << endl;
    cout << "======================================" << endl;
    cout << "1. Find item frequency" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "--------------------------------------" << endl;
}

bool Grocery::openInputFile(ifstream& inFile, const string& fileName) {
    inFile.open(fileName);
    return inFile.is_open();
}

bool Grocery::openOutputFile(ofstream& outFile, const string& fileName) {
    outFile.open(fileName);
    return outFile.is_open();
}

map<string, int> Grocery::readInputFile(ifstream& inFile) {
    map<string, int> grocList;   // Ordered map for item frequencies
    string item = "";            // Stores each line/item from the file

    // Read line-by-line using getline (supports multi-word items)
    while (getline(inFile, item)) {
        if (!item.empty()) {
            grocList[item]++;    // map initializes new int values to 0 automatically
        }
    }

    return grocList;
}

void Grocery::writeOutputFile(ofstream& outFile, const map<string, int>& grocList) {
    // Write each item and its frequency to the backup file
    for (const auto& pair : grocList) {
        outFile << pair.first << " " << pair.second << endl;
    }
}

void Grocery::findItem(const map<string, int>& grocList) {
    string searchItem = "";      // Item to search for
    int count = 0;               // Frequency result

    // Safe for mixing cin >> and getline
    cin.clear();
    cout << "Enter the item you would like to search for: ";
    getline(cin, searchItem);

    auto it = grocList.find(searchItem);
    if (it != grocList.end()) {
        count = it->second;
    } else {
        count = 0;
    }

    cout << searchItem << " was purchased " << count << " time(s)." << endl;
}

void Grocery::listItems(const map<string, int>& grocList) {
    cout << "Item Frequencies" << endl;
    cout << "----------------" << endl;

    for (const auto& pair : grocList) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void Grocery::printHistogram(const map<string, int>& grocList) {
    cout << "Histogram" << endl;
    cout << "---------" << endl;

    for (const auto& pair : grocList) {
        cout << pair.first << " " << string(pair.second, '*') << endl;
    }
}