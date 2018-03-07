/*
Jeffrey Garip
Cs 1124
hW02
allow warriors to fight;
*/


#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;


struct Warrior {
	string name;
	int power;
};


void fillNstore(ifstream& file, vector<Warrior>&lst,string& name,int pl) {
	// creates warrior based on information passed to function
	
	Warrior Man;
	Man.name = name;
	Man.power = pl;
	lst.push_back(Man);
	
	
}


void displayStatus(const vector<Warrior>&list) {
	// displays contents of vector using ranged for;
	// I used range for based because i consider it easier to read
	cout << "there are " << list.size() <<" "<< "Warrior" << endl;

	for (const Warrior& person : list)
	{
		cout << "Warrior: " << person.name << ", " << "Strength: " << person.power << endl;

	}

}
	
void Battle(Warrior& man, Warrior& man2)
//  allows warriors  to do battle
{
	cout << man.name << " Battles " << man2.name << endl;
	if (man.power < man2.power) {
		if (man.power<=0) { cout << "He's dead " << man2.name<<endl; }

		else { 
			man2.power -= man.power;
			man.power = 0;
		}
	}
	else if (man.power <= 0 && man2.power <= 0) {
		// checks to see if powers are both less than or equal to zero
		cout << "Oh, NO! They're both dead! Yuck!" << endl;
	}
	else if (man.power == man2.power) {
		/// checks to see if powers are equals
		cout << "Mutual Annihalation:" << man.name << " and " << man2.name
			<< " die at each other's hands" << endl;
		man.power = 0;
		man2.power = 0;
	
	}

	

	else {

		if (man2.power < man.power) {
			if (man2.power <= 0) {
				cout << "He's dead " << man.name<<endl;
			}




			else {
				man.power -= man2.power;
				man2.power = 0;
			}


		}




	}
}



int findWarrior(const vector<Warrior>&wv, const string& name) 
{
	for (int index = 0; index < wv.size(); index++) {
		
		if (wv[index].name == name)
		{
			return index;
		}

	}
	return wv.size();
}










int main() {
	ifstream fighterStream("Warriors.txt");
	if (!fighterStream) { cerr << "can't open crash!!!\n"; exit(2); }
	string Selection;
	string name;
	string name2;
	int power;
	vector<Warrior>group;
	
	while (fighterStream >> Selection)
	{

		if (Selection == "Warrior") {
			string name;
			string name2;
			int strength;
			fighterStream >> name >> strength;
			fillNstore(fighterStream,group,name,strength);
		}
	
		if (Selection == "Status") {
			displayStatus(group);
		}

	
		if (Selection == "Battle") {
			
			fighterStream >> name;
			fighterStream >> name2;
			int index1= findWarrior(group, name);
			int index2= findWarrior(group,name2 );
			Battle(group[index1],group[index2]);



		}
	
	}



	
	


}










