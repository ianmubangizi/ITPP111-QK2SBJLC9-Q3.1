// ITPP111_QK2SBJLC9_Q3.1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cctype>
#include <locale>

using namespace std;

// Global Varibles
bool	rd = true;
double	_lst, _hst, _outM, _inM, _passM, _cAvg = 0,
		_numStd = 0,_cTotal = 0, student[75];
string input;
int records;

/* Input Validate Function
*	Takes in a double
*	Checks if the doible 
*	 is <= 0
*	Return input if *[n]-false
*/
double inputVal(double a) {
	bool b = true;
	while (b) { 
		if (cin.fail() || a <= 0) {
			if (cin.fail()) {
				cout << "Invaild Input! Can't input a Letter\n";
			cin.clear(); cin.ignore(LLONG_MAX, '\n');
			}
			else if (a <= 0) {
				cout << "Invaild Input! Can't input 0\n";
			}
			cout << "Please Try Again\n\n[Input] : "; cin >> a;
		} else {
			b = false; 
		}
	}
	return a;
}

/* High Low Function()
*	Takes in an Integer
*	sets array[n] to int
*/
void hl(int a) {
	if (a == 0) { 
		_hst = student[a]; _lst = student[a];
	}
	if (student[a] > _hst) {
		_hst = student[a];
	}
	else if (student[a] < _lst) {
		_lst = student[a];
	}
}

/* Calculation Function()
*	Take in a Double and Integer
*	Sets High and Low from void hl()
*	10% added to input double
*/
void _calfunc(double m, int a) {
	if (a == 0) {
		hl(a); 
		m = student[a] + (student[a] * 0.10);
		student[a] = m;
	}
	else { hl(a);
	     }
	if (student[a] >= _passM) {
		records = records + 1;
	}
	_numStd = _numStd + 1; _cTotal = _cTotal + student[a];
	_cAvg = _cTotal / _numStd;
}

//Display Marks()
void _disMark() {
	cout << "================================================\n";
	printf("Class Avg = [%.2f%s", _cAvg, "%]\n");
	printf("Class Lowest = [%.0f%s", _lst, "%]\n");
	printf("Class Highest = [%.0f%s", _hst, "%]\n");
	printf("Students = [%.0f%s", _numStd, "]\n");
	printf("Students that Passed = [%d%s", records, "]\n");
	printf("Pass Rate = [%.2f%s", ((records / _numStd) * 100), "%]\n");
	cout << "================================================\n";
}



/* String Input()
*	Takes in a string 
*	Sets an = value string from
*	 no||yes[n] in _input()
*	returns that value
*/
bool _input(string a) {
	bool b = false;
	string yes[5] = {"y","yes", "Y","Yes","YES"};
	string no[5] = {"n","no","N","No","NO"};
		for (int i = 0; i < 5; i++) {
			if (a == yes[i]) { b = true; i = 5;}
			else if(a == no[i]) { b = false; i = 5;}
		}
	return b;
}


/* Main Function
*
*/
int main() {
	// Do While
	do {
		cout << "=================================================\n";
		cout << "What is the Pass Mark? : "; cin >> _passM; inputVal(_passM);
		cout << "What is the Total Mark? : "; cin >> _outM; inputVal(_outM);
		cout << "=================================================\n";
		for (int a = 0; a < 75; a++) {
			printf("|| Enter Mark for student [%d] : ", (a + 1));
			cin >> student[a]; inputVal(student[a]); _calfunc(student[a], a);
			printf("|| Mark for Student [%d] is [%.0f]\n", (a + 1), student[a]);
			cout << "=================================================\n";
			if (a != 0) { if ((a % 5) == 0) {
				printf("Do you want to continue [Yes/No] : "); cin >> input;
				cout << "=================================================\n";
				if (!_input(input)) { a = 2; a = 75; rd = false; }}
			}
		}
		_disMark();
	} while (rd);
	cin.get();
}
