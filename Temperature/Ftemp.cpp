#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Input file stream (reading)
    ifstream inputFile;

    // Output file stream (writing)
    ofstream outputFile;

    string cityName;
    int tempF;
    double tempC;

    // Open the input file
    inputFile.open("FahrenheitTemperature.txt");

    // Check if the input file opened successfully
    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    // Open the output file
    outputFile.open("CelsiusTemperature.txt");

    // Check if the output file opened successfully
    if (!outputFile.is_open()) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    // Read each city and temperature, convert, and write to output file
    while (inputFile >> cityName >> tempF) {
        // Convert Fahrenheit to Celsius
        tempC = (tempF - 32) * 5.0 / 9.0;

        // Write city name and Celsius temperature to output file
        outputFile << cityName << " " << tempC << endl;
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    cout << "Temperature conversion complete. Check CelsiusTemperature.txt." << endl;

    return 0;
}
