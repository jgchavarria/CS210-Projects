#include <iostream>
#include <iomanip>
using namespace std;

// Structure to store time
struct Time {
    int hour;
    int minute;
    int second;
};

// Gets initial time from the user
Time GetInitialTime() {
    Time t;

    cout << "Enter hour (0-23): ";
    cin >> t.hour;

    cout << "Enter minute (0-59): ";
    cin >> t.minute;

    cout << "Enter second (0-59): ";
    cin >> t.second;

    return t;
}

// Adds one hour
void AddHour(Time& t) {
    t.hour++;
    if (t.hour == 24) {
        t.hour = 0;
    }
}

// Adds one minute
void AddMinute(Time& t) {
    t.minute++;
    if (t.minute == 60) {
        t.minute = 0;
        AddHour(t);
    }
}

// Adds one second
void AddSecond(Time& t) {
    t.second++;
    if (t.second == 60) {
        t.second = 0;
        AddMinute(t);
    }
}

// Displays both clocks
void DisplayClocks(const Time& t) {
    int hour12;
    string period;

    if (t.hour >= 12) {
        period = "PM";
    } else {
        period = "AM";
    }

    hour12 = t.hour % 12;
    if (hour12 == 0) {
        hour12 = 12;
    }

    cout << "**************************  **************************\n";
    cout << "*      12-Hour Clock     *  *      24-Hour Clock     *\n";

    cout << "*      "
         << setfill('0') << setw(2) << hour12 << ":"
         << setw(2) << t.minute << ":"
         << setw(2) << t.second << " " << period
         << "      *  *        "
         << setw(2) << t.hour << ":"
         << setw(2) << t.minute << ":"
         << setw(2) << t.second
         << "        *\n";

    cout << "**************************  **************************\n\n";
}

// Displays the menu
void DisplayMenu() {
    cout << "**************************\n";
    cout << "* 1 - Add One Hour       *\n";
    cout << "* 2 - Add One Minute     *\n";
    cout << "* 3 - Add One Second     *\n";
    cout << "* 4 - Exit Program       *\n";
    cout << "**************************\n";
}

// Runs the clock program
void RunClock() {
    Time currentTime = GetInitialTime();
    int choice = 0;

    while (choice != 4) {
        DisplayClocks(currentTime);
        DisplayMenu();

        cout << "Select an option (1-4): ";
        cin >> choice;

        if (choice == 1) {
            AddHour(currentTime);
        } else if (choice == 2) {
            AddMinute(currentTime);
        } else if (choice == 3) {
            AddSecond(currentTime);
        }
    }

    cout << "Program ended.\n";
}

int main() {
    RunClock();
    return 0;
}
