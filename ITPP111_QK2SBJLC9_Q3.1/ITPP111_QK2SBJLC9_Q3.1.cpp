// ITPP111_QK2SBJLC9_Q3.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Varibles
bool	rd = true;
double	_lowest, _highest, _outMark, _intiMark, _passMark,
		_classAvg = 0,
		_numStudent = 0,
		_classTotal = 0;

string input;
vector<vector<int>> records(2, vector<int>(1));
vector<vector<double>> student(2, vector<double>(1));

/*	Input Mark()
*		Takes in a double
*		From first input
*		Checks if input is >= 0
*		Return input if true
*/
double _inputNum(double a, int b) {
	bool c = true;
	do {
		while (a == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "The Mark Has to be a number " << "!\n\nEnter Mark Again : "; 
			cin >> a;
		}
		a = a;
		c = false;
	} while (c);
	return a;
}

/*	High Low Function()
*	
*	
*/
void hl(int b, int c) {
	if (c == 0) {
		_highest = student[b][c];
		_lowest = student[b][c];
	}
	if (student[b][c] > _highest) {
		_highest = student[b][c];
	}
	else if (student[b][c] < _lowest) {
		_lowest = student[b][c];
	}
}

/*	Calculation Function()
*
*
*/
void _calfunc(double m, int a, int b) {

	if (a == 0) {
		hl(a, b);
		m = student[a][b] + (student[a][b] * 0.10);
		student[(a + 1)][b] = m;
	}
	else {
		hl(a, b);
	}
	if (student[a][b] >= _passMark) {
		records[a][0] = records[a][0] + 1;
	}
	_numStudent = _numStudent + 1;
	_classTotal = _classTotal + student[a][b];
	_classAvg = _classTotal / _numStudent;
}

/*	Display Marks()
*	
*	
*/
void _disMark(int a) {
	switch (a) {
		case 0:
			cout << "================================================\n";
			cout << "Class Avg = " << _classAvg << "\n";
			cout << "Class Total = " << _classTotal << "\n";
			cout << "Class Lowest = " << _lowest << "\n";
			cout << "Class Highest = " << _highest << "\n";
			cout << "================================================\n";
			cout << "numS = " << _numStudent << "\n";
			cout << "Pass1 = " << records[0][0] << "\n";
			break;
		case 1:
			cout << "================================================\n";
			cout << "New Class Avg = " << _classAvg << "\n";
			cout << "New Class Total = " << _classTotal << "\n";
			cout << "New Class Lowest = " << _lowest << "\n";
			cout << "New Class Highest = " << _highest << "\n";
			cout << "================================================\n";
			cout << "numS = " << _numStudent << "\n";
			cout << "Pass2 = " << records[1][0] << "\n";
			break;
		default:
			break;
	}
}

/*	String Input()
*
*
*/
bool _input(string a) {
	bool b = false;
	string yes[4] = {"y","yes","Yes","YES" };
	string no[4] = { "n","no","No","NO"};
		for (int i = 0; i < 4; i++) {
			if (a == yes[i]) {
				b = true;
				i = 5;
			}
			else if(a == no[i]) {
				b = false;
				i = 5;
			}
		}
	return b;
}

/* Main Function
*
*
*/
int main() {

	// Do While
	do {
		// For Loop for Base Mark and Final Mark + 10%
		for (int a = 0; a < 2; a++) {

			for (int b = 0; b < student[a].size(); b++) {

				// If Statment to check for Base index
				if (a == 0 && b == 0) {
					cout << "What is the Pass Mark? : "; cin >> _passMark;
					_passMark = _inputNum(_passMark, a);
					cout << "What is the Total Mark? : "; cin >> _outMark;
					_outMark = _inputNum(_outMark, a);
					cout << "\n";
				}

				if (a == 0) {
					// Populate the 1st row of student elements with marks
					cout << "Enter Mark for Student " << b + 1 << ". Mark : ";
					cin >> _intiMark;
					student[a][b] = _inputNum(_intiMark, a);

					cout << "Do you want to Add More Marks? Enter Yes/No : ";
					cin >> input;

					if (_input(input)) {
						student[a].push_back(0);
						student[(a + 1)].push_back(0);
					}
					else if (!_input(input)) {
						rd = false;
						b = b+1;
					}
				}
				_calfunc(student[a][b], a, b);
			}

			_disMark(a);
			_classAvg = 0;
			_classTotal = 0;
			_numStudent = 0;
		}

	} while (rd);
	cin.get();
}

