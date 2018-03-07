/*
Jeffrey Garip
cs 1124
hw 06 inhertance(Noble-Warrior Hw)


*/




#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;


class Lord;
class Protector {

public:
	Protector(const string&name, const double &power) : name(name), power(power), Lptr(nullptr),alive(true) {}
	void die() { this->power = 0; }
	void setpower(const double apower) { this->power = apower; }
	string getname()const { return name; }
	double getpower()const { return power; }
	Lord* getLord()const { return Lptr; }
	void setlord(Lord* const athing) {
		if (Lptr == nullptr) {
			Lptr = athing;
		}
	}

	virtual void battlecry() const = 0;
	bool isalive() { return alive; }

private:
	bool alive;
	bool hired;
	string name;
	double power;
	Lord* Lptr;

};

class Wizard : public Protector {
public:
	Wizard(const string &name, const double pl) :Protector(name, pl) {};
	void battlecry() const;
};

class Archer : public Protector {
public:
	Archer(const string& name, double power) : Protector(name, power) {};
	void battlecry() const;

};

class Swordsman :public Protector
{
public:
	Swordsman(const string& name, const double pl) :Protector(name, pl) {};
	void battlecry() const;

};

class Noble {
public:
	Noble(const string &name):name(name), alive(true) {};
	string getname()const { return name; }
	virtual double getpower() const = 0;
	virtual void setpower(const double apower) = 0;
	virtual void battle(Noble&foe);
	bool getAlive()const { return alive; }
	virtual void battlecry() = 0;
	virtual void killstrength(const double &apower = 0)=0;
	void setdead() { alive = false; }

private:
	bool alive;
	string name;

};

class PersonWithStrengthToFight: public Noble 
{
public:
	PersonWithStrengthToFight(const string& name, const double apl) :Noble(name),power(apl) {};
	double getpower() const { return power; }
	void setpower(const double apower) { this->power = apower; }
	void killstrength(const double &apower = 0) { power = apower; }
	void battlecry() { // no action
	}
private:
	double power;


};

class Lord :public Noble{
public:
	Lord(const string &name) : Noble(name) {};

	void battlecry() { 
		
		for (size_t pos(0); pos < defenders.size(); ++pos )
		{
			defenders[pos]->battlecry();
		}
		
	}

	void hires(Protector& worker)
	{
		if (worker.getLord() == nullptr && worker.isalive())
		{
			Protector* wptr = &worker;
			defenders.push_back(wptr);

			worker.setlord(this);
		}
	}

	void setpower(const double pain)
	{
		for (size_t ndx = 0; ndx < defenders.size(); ndx++) 
		{
          defenders[ndx]->setpower(defenders[ndx]->getpower()- defenders[ndx]->getpower()*pain);
		}

	}

	double getpower() const {
		double power = 0;
		for (const Protector* pptr : defenders)
		{
			power += pptr->getpower();
		}
		return power;
	}

	void killstrength(const double &apower = 0) {

		for (Protector* pptr : defenders)
		{
			pptr->setpower(0);
		}

	}

private:	
	
	vector<Protector*>defenders;

};


// outside definitions of the class;
//---------------------------------------------------------------------------------------------------------

void Noble::battle(Noble & foe)
{
	double mypower = getpower();
	double foepower = foe.getpower();
	cout << name << " battles " << foe.name << endl;
	if (getAlive())
	{
		if (foe.getAlive())
		{
			battlecry();
			foe.battlecry();
			if (mypower < foepower) 
			{
				double ratio = foepower /mypower ;
				cout << foe.getname() << " defeats " << getname() <<endl;
				killstrength();
				foe.setpower(getpower() - ratio*getpower());
				setdead();
			}
		}
		else
		{
			cout << "He's dead " << name << endl;

		}

	}
	else {

		if (foe.getAlive()) 
		{
			cout << "He's dead, " << foe.getname() << endl;
		}
	
		else
		{
			cout << " Mutual Annihalation : " << getname()
					<< " and "<< foe.getname() 
				<< " die at each other's hands" 
				<< endl;

			killstrength();
			foe.killstrength();
			foe.setdead();
			setdead();
		}	
	}

}//the end of functions 

void  Wizard::battlecry()const  {
	cout << "POOF!\n";
}

void Archer::battlecry()const  {

	cout << "TWANG! " << getname()
		<< " says: Take That in the name of my lord, "
		<< getLord()->getname() << endl;
}

void Swordsman::battlecry()const{
	cout << "CLANG! " << getname()
		<< " says: Take that in the name of my lord, " << getLord()->getname() <<endl;
}

int main() {

	
		Lord sam("Sam");
		Archer samantha("Samantha", 200);
		sam.hires(samantha);
		Lord joe("Joe");
		PersonWithStrengthToFight randy("Randolf the Elder", 250);
		joe.battle(randy);
		joe.battle(sam);
		Lord janet("Janet");
		Swordsman hardy("TuckTuckTheHardy", 100);
		Swordsman stout("TuckTuckTheStout", 80);
		janet.hires(hardy);
		janet.hires(stout);
		PersonWithStrengthToFight barclay("Barclay the Bold", 300);
		janet.battle(barclay);
		janet.hires(samantha);
		Archer pethora("Pethora", 50);
		Archer thora("Thorapleth", 60);
		Wizard merlin("Merlin", 150);
		janet.hires(pethora);
		janet.hires(thora);
		sam.hires(merlin);
		janet.battle(barclay);
		sam.battle(barclay);
		joe.battle(barclay);
	














	
	system("pause");



}










