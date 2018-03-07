/*
Jeffrey Garip
Sandwich lab 
CS1124

*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Sandwich {
public:
	Sandwich() {};
	Sandwich( const int& acheese, const int& aMayo, const int& atomato,
		const double& amustard, const int& abreads = 2) : numbread(abreads), cheese(acheese), mayonase(aMayo),
		tomatato(atomato), mustard(amustard){};


	void displays() {
		cout << " number of bread:  " << numbread << endl
			<< " number of  cheese: " << cheese << endl
			<< "amount of mayo: " << mayonase << endl
			<< " number of tomato: " << tomatato << endl
			<< " amount o mustard: " << mustard << endl;
	}

	int getbread()const {return numbread;}
	int getcheese()const { return cheese ; }
	int getMayo() const { return mayonase; }
	int getTomato() const { return tomatato; }
	int getmustard() const{ return mustard; }

	
	int setcheese(const int cheese)const { return cheese; }
	int setMayo(const int mayos) const { return mayonase; }
	int setTomato(const int tomatos) const { return tomatato; }
	int setmustard(const double mustards) const { return mustard; }





private:
	const int numbread=2;
	int cheese=1;
	int mayonase=1;
	int tomatato=2;
	double mustard=0.5;
	

};



class DTruck{
public:
	void insertSandwich(const Sandwich& subways) {
		SandwichGroup.push_back(subways);
	
	}

	void displaybeforeLeaving() 
	{
		for ( Sandwich& sandmeal : SandwichGroup) {
			sandmeal.displays();


		}
	
	
	}

private:
	vector<Sandwich>SandwichGroup;
	Sandwich aSand;



};








int main() {
	
	Sandwich Blt;
	Sandwich reg(2, 3, 2, 3.4);
	reg.setmustard(0);
	Sandwich Blt2;

	DTruck atruck;
	atruck.insertSandwich(Blt);
	atruck.insertSandwich(reg);
	atruck.insertSandwich(Blt2);
	atruck.displaybeforeLeaving();

	



}




