#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <limits>

using namespace std;

const int MAX_INTEGER = numeric_limits<int>::max();

class Grocery {
public:
    void displayMenu();

    bool openInputFile(ifstream& inFile, const string& fileName);
    bool openOutputFile(ofstream& outFile, const string& fileName);

    map<string, int> readInputFile(ifstream& inFile);
    void writeOutputFile(ofstream& outFile, const map<string, int>& grocList);

    void findItem(const map<string, int>& grocList);
    void listItems(const map<string, int>& grocList);
    void printHistogram(const map<string, int>& grocList);
};