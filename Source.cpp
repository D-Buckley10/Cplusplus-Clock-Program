/*Douglas Buckley
Professor Chan
CS-210-T5548 Project One: Chada Tech Clocks
May 22, 2022*/

#include <iostream>
#include <string>

using namespace std;
// Global variables for hours, minutes, and seconds
unsigned int h = 0;
unsigned int m = 0;
unsigned int s = 0;


// Function to create two digit string
string twoDigitString(unsigned int n) {
    string tDS;  // Initiate string
    tDS = to_string(n);  // Assign string to integer converted to string
    if (tDS.size() < 2) {  // If loop to check the size of new string
        tDS = '0' + tDS; // Puts leading zero if appropriate
    }
    return tDS; // Return value
}

// Function to output string of certain character
string nCharString(size_t n, char c) { 
    string nCS = ""; // Initiate and assign string to empty string
    nCS.resize(n, c); // Change the string to output c and length n
    return nCS;
}

// Function to output string that formats the 24 hour time
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string formatTimeTF; // Initiate string
    formatTimeTF = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s); // Create appearance of string while calling twoDigitString function
    if (h >= 24) { // If loop to reset hours to zero is hours exceeds 24
        h = 0;
        formatTimeTF = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s); // Change value of new string
    }
    if (m > 59) { // If loop to add one hour is minutes exceeds 60 and reset minutes to 0
        m = 0;
        h += 1;
        formatTimeTF = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s); // Change value of new string
    }
    if (s > 59) { // If loop to add a minute if seconds exceeds 60 and to reset seconds to 0
        s = 0;
        m += 1;
        formatTimeTF = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s); // Change value of new string
    }
    return formatTimeTF; // Return string
}

// Function to output string that formats the 12 hour time
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string formatTimeTH;

    if ((h < 12) && (h > 0)) { // If loop to check for AM time
        formatTimeTH = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";  // Change value of the string
    }
    if (h == 0) { // If loop to change the 24 hour 00 to the 12 hour 12 AM
        formatTimeTH = twoDigitString(12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";  // Change value of the string
    }
    if (h > 12) { // If loop to change 24 HR time to 12 HR PM time
        h = h - 12;
        formatTimeTH = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M"; // Change value of the string
    }
    if (h == 12) { // If loop to check for PM time
        formatTimeTH = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";  // Change value of the string
    }
    if ((m > 59) && (h < 12) && (h > 0)) { // If loop to add an hour if the minutes were to exceed 60
        m = 0;
        h += 1;
        formatTimeTH = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";  // Change value of the string
    }
    if ((s > 59) && (h < 12) && (h > 0)) { // If loop to add a minute if seconds were to exceed 60
        m += 1;
        formatTimeTH = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(0) + " A M";  // Change value of the string
    }
    if ((m > 59) && (h >= 11)) {  // If loop to add an hour and change AM to PM
        m = 0;
        h += 1;
        formatTimeTH = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";  // Change value of the string
    }

    return formatTimeTH; // Return String
}

// Function to Display clocks
void displayClocks() {
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl; // Calling nCharString function to output characters
    cout << "*      12-HOUR CLOCK      *   " << "*      24-HOUR CLOCK      *" << endl; // Label which clocks are 12 HR and 24 HR
    cout << "*      " << formatTime12(h, m, s) << "       *   "; // Calling formatTime12 function to output time formated with twoDigitString function already
    cout << "*        " << formatTime24(h, m, s) << "         *" << endl;  // Calling formatTime24 function to output time formated with twoDigitString function already
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;  // Calling nCharString function to output characters
}

// Function to Display the userMenu
void printMenu() {
    cout << nCharString(15, ' ') << nCharString(27, '*') << endl; // Calling nCharString function to output characters
    cout << nCharString(15, ' ') << "* 1- Add One Hour" << nCharString(9, ' ') << '*' << endl; // Calling nCharString function to output characters and display first choice
    cout << nCharString(15, ' ') << "* 2- Add One Minute" << nCharString(7, ' ') << '*' << endl;  // Calling nCharString function to output characters and display first choice
    cout << nCharString(15, ' ') << "* 3- Add One Second" << nCharString(7, ' ') << '*' << endl;  // Calling nCharString function to output characters and display second choice
    cout << nCharString(15, ' ') << "* 4- Exit Program" << nCharString(9, ' ') << '*' << endl;  // Calling nCharString function to output characters and display third choice
    cout << nCharString(15, ' ') << nCharString(27, '*') << endl;  // Calling nCharString function to output characters
}

// Main Function
int main(){
    displayClocks();  // Displays clocks
    printMenu(); // Display user menu
    int choice; // Initialize character variable
    cin >> choice;  // Request user input to dictate program path
    while (choice != 4) { // While loop to allow program to run until terminated by user
        switch (choice) { // Switch statement for menu option picked by user
        case 1: // Create case to add one hour to clocks
            h += 1;  // Increases hour by one
            cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;// Calling nCharString function to output characters
            cout << "*      12-HOUR CLOCK      *   " << "*      24-HOUR CLOCK      *" << endl;
            cout << "*      " << formatTime12(h, m, s) << "       *   ";
            cout << "*        " << formatTime24(h, m, s) << "         *" << endl;
            cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;// Calling nCharString function to output characters
            printMenu();  // Display the user menu
            cin >> choice; // Request another input from user
            break; // Break case scenario
        case 2: // Create case to add one minute to clocks
            m += 1;  // Increase minute by one
            cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;// Calling nCharString function to output characters
            cout << "*      12-HOUR CLOCK      *   " << "*      24-HOUR CLOCK      *" << endl;
            cout << "*      " << formatTime12(h, m, s) << "       *   ";
            cout << "*        " << formatTime24(h, m, s) << "         *" << endl;
            cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;// Calling nCharString function to output characters
            printMenu();  // Display the user menu
            cin >> choice;  // Request another input from user
            break;  // Break case scenario
        case 3:  // Create case to add one second to clocks
            s += 1;  // Increase second by one
            cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;// Calling nCharString function to output characters
            cout << "*      12-HOUR CLOCK      *   " << "*      24-HOUR CLOCK      *" << endl;
            cout << "*      " << formatTime12(h, m, s) << "       *   ";
            cout << "*        " << formatTime24(h, m, s) << "         *" << endl;
            cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;// Calling nCharString function to output characters
            printMenu();  // Display the user menu
            cin >> choice;  // Request another input from user
            break;  // Break case scenario
        case 4:  // Create case to end program
            cout << "Thank you for using Chada Tech Clock service! Have a great day!" << endl;  // Display exit message
            exit(0);  // End the program
        default:  // Create default scenario to verify input
            cout << "Please enter one of the four options displayed in the menu" << endl;  // Display message for user to input a proper option
            printMenu(); // Display the user menu
            cin >> choice;  // Request another input from user
            break;  // Break default scenario
        }
    }
    return 0;
}