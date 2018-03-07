/*
Programer: Jeffrey Garip
Class: CS 1124
Professor: Sterling
objective: 
create warrior with a weapon born from within.


*/



#include<iostream>
#include<fstream>
#include<vector>
#include <string>
using namespace std;

class Weapon {
public:
	Weapon(const string& Name, const int pl) :aName(Name), aPower(pl) {};
	int getWPower()const { return aPower; }
	void setpower(const int pl) { aPower = pl; }
	string getWName()const{ return aName; }
private:
	string aName;
	int aPower;

};


class Warrior {
public:
	Warrior(const string& alias, const string& Weapon, const int pl)
		:aname(alias), Item(Weapon, pl){};
	string getWarName() const;
	int getpower()const;
	string getWeapon()const;
	void setpower(const int pl);
	void battle(Warrior& another);
	void selfdestruct() { Item.setpower(0); }






private:
	Weapon Item;
	string aname;




};











void FileChecker(ifstream&aFile) {
	// checks for file I/o crashes program if file not found
	if (!aFile) { cerr << "Error Can't open.\n"; exit(2); }
}


int findWarrior(const vector<Warrior>&group, const string& name) 
{
	// function finds index in where the warrior is in the vector;
	for (size_t index = 0; index < group.size(); index++) {

		if (group[index].getWarName() == name) 
		{
			return index;
		}
	}
	return group.size();
}





int main()
{
	ifstream WarriorStream("warriors.txt");
	vector<Warrior>wgroup;
	string Action;
	FileChecker(WarriorStream);
	while (WarriorStream >> Action)
	{
		if (Action == "Warrior") {
			string name;
			string aweapon;
			int power;
			WarriorStream >> name >> aweapon >> power;
			Warrior Man( name,aweapon,power);
			wgroup.push_back(Man);

		}



		else if (Action == "Status") 
		{
			cout << "There are: " << wgroup.size() << " Warriors" << endl;
			
			for (size_t index = 0; index < wgroup.size(); index++)
			{
				cout << "Warrior: "
				<< wgroup[index].getWarName()
				<< ", " << "weapon: " << wgroup[index].getWeapon()<<", "
			    << wgroup[index].getpower() << endl;
			
			
			
			}

		}
	
		else if (Action == "Battle")
		{
			string Name1, Name2;
			int strength;
			WarriorStream >> Name1 >> Name2;
			int pos1 = findWarrior(wgroup, Name1);
			int pos2= findWarrior(wgroup, Name2);
			wgroup[pos1].battle(wgroup[pos2]);



		}

	
	
	
	
	}//while loop brace

	WarriorStream.close();
	WarriorStream.seekg(0);
	// closing the file and setting the file pointer



}


// definition of member functions outside class 
// prototypes built inside functions

string Warrior::getWarName() const
{
	// returns name by const, disallowing change to whats being returned
	return aname;
}

int Warrior::getpower() const
{
	// returns warriors strength by const through that of the weapon class;
	return Item.getWPower();
}

string Warrior::getWeapon() const
{	
	// returns weapons name by const construct
	return Item.getWName();
}

void Warrior::setpower(const int pl)
{	// sets weapons power by value passed in by const val
	Item.setpower(pl);
}

void Warrior::battle(Warrior & another)
{
	// battle function which test four senarios
	cout << getWarName() << " battles " << another.getWarName() << endl;
	if (getpower() > another.getpower()) {
		if (another.getpower() <= 0)
		{
			cout << "He's dead " << getWarName() << endl;
		}

		else {
			int damage = getpower() - another.getpower();
			setpower(damage);
			another.selfdestruct();
			cout << getWarName()
				<< " defeats " << another.getWarName() 
				<<endl;



		}
	}

	else if (another.getpower()>getpower()) {

		if (getpower()<=0)
		{
			cout << "He's dead, " << another.getWarName();
		}

		else {
			int mydamage = another.getpower() - getpower();
			another.setpower(mydamage);
			selfdestruct();
			cout << another.getWarName()
				<< " defeats " << getWarName()
				<< endl;





		}


	
	
	
	
	
	}

	


	else if (another.getpower() <= 0 && getpower()<=0) 
	{
		cout << "Oh,NO! they're both dead! Yuck!\n";

	}

	else if (another.getpower() == getpower())
	{
		cout << "Mutual Annihilation: " << getWarName() << " and "
			<< another.getWarName() << " die at each other's hands" << endl;
		another.selfdestruct();
		selfdestruct();

	}






}






