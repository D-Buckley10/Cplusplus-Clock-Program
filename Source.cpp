/* Douglas Buckley
   CS-210 Project 1: Chada Tech Clocks
   5/16/22 
 */

//TODO: Set comments for written lines of code before adding more
//TODO: Figure out how to display clocks side by side
//TODO: Create opiton menu that requires user input

#include <iostream>
#include <iomanip>  
#include <string>
#include <ctime>
using namespace std;


void twoDigitString(unsigned int n) {
	cout << setw(2) << setfill('0') << n << endl;
}
void menuDisplay() {

}

void clockDisplay(unsigned int clock12Hour, unsigned int clockMinute, unsigned int clockSecond, string tod) {
	unsigned int clock24Hour = clock12Hour + 12;
	if (tod == "AM") {
		clock24Hour = clock12Hour;
	}
	cout << setw(26) << left << setfill('*') << "";
	cout << "     ";
	cout << setw(26) << right << setfill('*') << "" << endl;
	cout << left << "*      12-Hour Clock     *";
	cout << "     ";
	cout << left << "*      24-Hour Clock     *" << endl;
	cout << left << "*       " << clock12Hour << ":" << clockMinute << ":" << clockSecond << " " << tod << "       *";
	cout << "     ";
	cout << left << "*        " << clock24Hour << ":" << clockMinute << ":" << clockSecond << "        *" << endl;
	cout << setw(26) << left << setfill('*') << "";
	cout << "     ";
	cout << setw(26) << right << setfill('*') << "" << endl;
}

int main() {
	clockDisplay(1, 15, 25, "PM"); 
	return 0;
}