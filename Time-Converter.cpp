/* Project One - CS 210.cpp */

/* Developer: Valerie Meiners
 * Date: July 9, 2023
 * Program: Chada Tech Clocks
*/

#include <iostream>
#include <string> // to append character to string
using namespace std;

string twoDigitString(unsigned int n) { // function to create string from two digits
	string newNum;

	if (n < 10) {
		newNum = "0" + to_string(n);
	}
	else {
		newNum = to_string(n);
	}
	return newNum;
}

void printStar(char n, int c) { // function to repeat asterisks, utilizes <string> 
	cout << string(n, c) << endl;
}

string formatTime24(unsigned int hours, unsigned int minutes, unsigned int seconds) { // function to format in 24 hr time

	string finishedTime24; //create blank string

	string hoursString = twoDigitString(hours);
	string minutesString = twoDigitString(minutes);
	string secondsString = twoDigitString(seconds);

	finishedTime24 = hoursString + ":" + minutesString + ":" + secondsString;
	return finishedTime24;
}

string formatTime12(unsigned int hours, unsigned int minutes, unsigned int seconds) { // function to format in 12 hr time

	string finishedTime12; // create blank string
	string nightDay; // to determine AM or PM 

	if (hours >= 13 && hours <= 23) {
		nightDay = " PM";
		if (hours >= 13) {
			hours -= 12; // convert 24 hr time to 12 hr time
		}
	}

	else if (hours == 0) {
		nightDay = " AM";
		hours = 12; // convert 24 hr time to 12 hr time
	}

	else if (hours > 0 && hours < 12) {
		nightDay = " AM";
	}
	else if (hours == 12) {
		nightDay = " PM"; 
	}

	string hoursString = twoDigitString(hours);
	string minutesString = twoDigitString(minutes);
	string secondsString = twoDigitString(seconds);

	finishedTime12 = hoursString + ":" + minutesString + ":" + secondsString + nightDay;
	return finishedTime12;
}

void displayMenu() { // function to display menu

	printStar(26, '*'); // call function for asterisks 
	cout << "*  1. Add One Hour       *" << endl;
	cout << "*  2. Add One Minute     *" << endl;
	cout << "*  3. Add One Second     *" << endl;
	cout << "*  4. Exit Program       *" << endl;
	printStar(26, '*'); // call function for asterisks   
}

/* function prototypes - tells program which types of
   values will be utilized in menuChoice function
*/
void addOneHour(int& seconds, int& minutes, int& hours);
void addOneMinute(int& seconds, int& minutes, int& hours);
void addOneSecond(int& seconds, int& minutes, int& hours);

unsigned int menuChoice(int& seconds, int& minutes, int& hours, int& maxChoice) { // function for menu choice

	cout << "Enter Menu Choice: ";
	cin >> maxChoice;

	if (maxChoice == 1) { // adds one hour
		addOneHour(seconds, minutes, hours);
	}
	else if (maxChoice == 2) { // adds one minute
		addOneMinute(seconds, minutes, hours);
	}
	else if (maxChoice == 3) { // adds one second
		addOneSecond(seconds, minutes, hours);
	}
	else if (maxChoice == 4) { // exits program
		cout << "Goodbye." << endl;
		return false;
	}
	return true;
}

/* Could not determine how to display clocks side by side. 
   Included clocks, one on top of the other, to illustrate
   that both times are displayed from the program. 
   It is likely an issue stemming from incorrect utilization 
   of the printStar function to print asterisks. 
*/
void displayClocks(unsigned int hours, unsigned int minutes, unsigned int seconds) { // function to display clocks

	printStar(27, '*'); 
	cout << "*" << "      " << "12 - HR CLOCK" << "      " << "*" << "   " << endl;
	cout << "*" << "      " << formatTime12(hours, minutes, seconds) << "        " << "*" << "   " << endl;
	printStar(27, '*');
	cout << "*" << "      " << "24 - HR CLOCK" << "      " << "*" << "  " << endl;
	cout << "*" << "      " << formatTime24(hours, minutes, seconds) << "           " << "*" << endl;
	printStar(27, '*');
}

void addOneSecond(int& seconds, int& minutes, int& hours) { // add seconds

	if (seconds >= 0 && seconds <= 58) {
		seconds = seconds + 1;
	}
	else if (seconds == 59) { 
		seconds = 0;
		minutes = minutes + 1;
	}
	if (minutes == 60) {
		hours = hours + 1;
		minutes = 0;
	}
	if (hours == 24) {
		hours = 0;
	}
}

void addOneMinute(int& seconds, int& minutes, int& hours) { // add minutes

	if (minutes >= 0 && minutes <= 58) {
		minutes = minutes + 1;
	}
	else if (minutes == 59) {
		hours = hours + 1;
		minutes = 0;
	}
	if (hours == 24) {
		hours = 0;
	}
}

void addOneHour(int& seconds, int& minutes, int& hours) { // add hours 

	if (hours >= 0 && hours <= 23) {
		hours = hours + 1;
	}
	if (hours == 24) {
		hours = 0;
	}
}

/* Attempted to include exception handling for user input 
   Attempt unsuccessful
*/
int main() { 
	int seconds; 
	int minutes;
	int hours;
	int maxChoice;

	cout << "Enter Seconds: "; // prompt for user input to give clock starting point
	cin >> seconds;
	cout << "Enter Minutes: ";
	cin >> minutes;
	cout << "Enter Hours: ";
	cin >> hours;

	while (true) { // call display menu to prompt for user input
		displayMenu();
		if (!menuChoice(seconds, minutes, hours, maxChoice)) {
			break;
		}
		displayClocks(hours, minutes, seconds);
	}
	return 0;
}
