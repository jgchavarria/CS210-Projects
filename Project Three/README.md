README – CS 210 Project Three: Corner Grocer Item Tracker
Project Summary

This project is a C++ console-based application called the Corner Grocer Item Tracker. 
The program reads a list of grocery items purchased throughout the day from an input file and analyzes how often each item appears. 
It stores the data in a map<string, int> and allows the user to search for item frequencies, display all item counts, and print a histogram of purchases.

The problem this program solves is helping a grocery store track purchasing trends. 
By analyzing how often each item is bought, the store can better understand customer demand and make smarter inventory decisions.

What I Did Particularly Well

One thing I did well in this project was organizing the program using a class structure. 
I created a Grocery class to handle menu display, file input/output, and item processing. 
This helped keep the code modular and organized instead of placing everything inside main().

I also used a map<string, int> from the C++ Standard Library effectively to automatically store and sort grocery items alphabetically while counting frequencies. 
This made the program efficient and clean.

Additionally, I included proper input validation and file checking to prevent crashes if the file could not be opened.

Areas for Improvement

Although the program works correctly, there are several areas where it could be improved:

- I could improve exception handling by using try and catch blocks instead of relying only on boolean file checks.

- The user interface could be enhanced with better formatting or possibly converted into a graphical interface.

- I could optimize input handling to better manage unexpected user inputs.

- The program could be expanded to allow editing, deleting, or adding items dynamically.

These improvements would make the program more secure, user-friendly, and scalable for real-world use.

Most Challenging Parts

The most challenging part of this project was working with file input/output and ensuring the map correctly stored item frequencies without duplication errors.

Another challenge was printing the histogram in a clean and readable format. 
I had to carefully loop through the map and print asterisks corresponding to item quantities.

I overcame these challenges by reviewing C++ documentation, practicing with small test examples, and debugging step-by-step using output statements.

Transferable Skills

This project strengthened several important programming skills that are transferable to other courses and projects:

- Working with file streams (ifstream, ofstream)

- Using STL containers like map

- Object-oriented design using classes

- Writing modular and maintainable code

- Input validation and error handling

- Designing menu-driven applications

These skills will be especially useful in future software development projects and systems programming courses.

Maintainability and Readability

I made the program maintainable and readable by:

- Separating functionality into clearly named member functions

- Using meaningful variable names

- Writing comments to explain the purpose of each function

- Keeping consistent formatting and indentation

- Avoiding unnecessary global variables

Because of this structure, the program can easily be expanded in the future without rewriting large sections of code.
