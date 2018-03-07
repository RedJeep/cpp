/*
Jeffrey Garip
CS2134
Question one
create combination lock that only accepts unique combinations
also disallows the copying of locks
*/

#include<iostream>
#include<string>

using namespace std;

class Combolock 
{
public:
	Combolock(int val = 0, int val1 = 0, int val2 = 0)
		: val(val),val2(val1), val3(val2),isOpen(false) {}
	
	Combolock(Combolock&rhs) {
		cerr << " can't make copy of lock ";
		exit(8);

	}

	Combolock operator=(const Combolock&rhs) {
		cerr << " can't make assignment of locks";
		exit(9);
	}


	bool open();
	void ChangeCombo();
	
	// this method was made so i can to test to see if the lock was made 
	// any change 
		void displayCombo()const {
		cout << "First : " << val << " Second: " << val2
			<< " Third: " << val3 << endl;
	}



private:
	int val;
	int val2;
	int val3;
	bool isOpen;

};

bool Combolock::open()
{
	
	cout << " Enter combinations To Open " << endl;
	int a;
	int b; 
	int c;
	cin >> a >> b >> c;
	if (val == a&&val2 == b&&val3 == c)
	{
		isOpen = true;
		cout << " Match, lock is currently open\n";
	
		return isOpen;

	}
	else {
		char token;
		cout<< "No match lock is closed sorry " << endl;
		isOpen = false;
		cout << " Would you like another chance to open lock Y/N ?";
		cin >> token;
		if (token == 'Y') {
			cin >> a;
			cin >> b; 
			cin >> c;
			if (val == a && val2 == b && val3 == c) {
				cout<< " Lock open ";
				isOpen = true;
				return isOpen;
			}
			else {
				cout << "sorry this was your last chance! " << endl;
			}
		}
		
		return isOpen;
	}



}

void Combolock::ChangeCombo()
// allows usr to change combo only if the new combos unique. 
{
	int a;
	int b;
	int c;
	
	cout << "Enter New combinations" << endl;
	cin >> a >> b >> c;
	if (val == a&& val2 == b && val3 == c) {
		cout << "same combinations" << endl;

	}

	else 
	{
		cout << " Combination changed " << endl;
		val= a;
		val2 = b;
		val3 = c;
	}

}



int main() 
{
	Combolock N;
	Combolock J(2, 1, 2);
	J.displayCombo();
	
	J.open();
	
	J.displayCombo();
	N = J;

}