/*
 * Jorge Chavarria
 * CS 210 Project Three - Corner Grocer Item Tracker
 *
 * Requirements met:
 *  - Uses a class with public/private structure (Grocery)
 *  - Uses ordered map<string,int>
 *  - Reads CS210_Project_Three_Input_File.txt
 *  - Writes frequency.dat at program start
 *  - Menu options 1-4 with input validation
 *  - Uses while(condition) loop (not while(true))
 *  - Uses getline for file input (supports multi-word items)
 */

#include "grocery.h"

int getInteger(int lowest, int highest, string prompt);
void pauseProgram(string prompt = "Press enter to continue ");
void cls();

const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
const string OUTPUT_FILE = "frequency.dat";

int main() {
    Grocery grocery;

    ifstream inputFile;          // Reads daily purchases
    ofstream outputFile;         // Writes backup file
    map<string, int> grocList;   // Ordered grocery frequency map
    int selection = 0;           // Menu selection

    // Open input file
    if (!grocery.openInputFile(inputFile, INPUT_FILE)) {
        cerr << "Error: Could not open input file: " << INPUT_FILE << endl;
        return EXIT_FAILURE;
    }

    // Open output file (created at program start)
    if (!grocery.openOutputFile(outputFile, OUTPUT_FILE)) {
        cerr << "Error: Could not open output file: " << OUTPUT_FILE << endl;
        return EXIT_FAILURE;
    }

    // Build frequency map from input file
    grocList = grocery.readInputFile(inputFile);

    // Write backup file
    grocery.writeOutputFile(outputFile, grocList);

    // Close files
    inputFile.close();
    outputFile.close();

    // Menu loop (condition-based)
    do {
        grocery.displayMenu();
        selection = getInteger(1, 4, "Please select menu option ");

        switch (selection) {
        case 1:
            cls();
            // Clear leftover newline before getline inside findItem
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            grocery.findItem(grocList);
            pauseProgram();
            cls();
            break;

        case 2:
            cls();
            grocery.listItems(grocList);
            pauseProgram();
            cls();
            break;

        case 3:
            cls();
            grocery.printHistogram(grocList);
            pauseProgram();
            cls();
            break;

        case 4:
            break;

        default:
            cout << "Invalid selection." << endl;
            break;
        }
    } while (selection != 4);

    cout << "Goodbye!" << endl;
    return 0;
}

int getInteger(int lowest, int highest, string prompt) {
    int number = 0;
    bool needNumber = true;

    prompt = prompt + to_string(lowest) + " and " + to_string(highest) + ": ";

    do {
        cout << prompt;
        cin >> number;

        if (cin.fail()) {
            cout << "Must be a number." << endl;
            cin.clear();
            cin.ignore(MAX_INTEGER, '\n');
            continue;
        }

        needNumber = (number < lowest) || (number > highest);
        if (needNumber) {
            cout << "Invalid number - please enter a value between "
                 << lowest << " and " << highest << "." << endl;
        }

    } while (needNumber);

    return number;
}

void pauseProgram(string prompt) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    cin.get();
}

void cls() {
    cout << "\x1B[2J\x1B[H";
    cout.flush();
}