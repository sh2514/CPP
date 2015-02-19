/* ======================================================
Builder Design Pattern
Shikuan Huang
====================================================== */

#include <iostream>
#include <string>
using namespace std;

class Game {	
friend ostream & operator<<(ostream & output, Game arg);

private:
	string name;
	string company;
	string country;
	int year;

public:
	Game(string name, string company, string country, int year) {
		this->name = name;
		this->company = company;
		this->country = country;
		this->year = year;	
	}
	
	class GameBuilder {
		private:
			string _name;
			string _company;
			string _country;
			int _year;
			
		public:
			static const string defaultName;
			static const string defaultCompany;
			static const string defaultCountry;
			static const int defaultYear = 1900;

			GameBuilder() : _name(defaultName), _company(defaultCompany), _country(defaultCountry), _year(defaultYear){}

			// Build function
			Game buildGame() {
				return Game(_name, _company, _country, _year);
			}
			
			GameBuilder & name(string n) {
				_name = n;
				return *this;	
			}
			
			GameBuilder & company(string c) {
				_company = c;
				return *this;
			}
			
			GameBuilder & country(string c) {
				_country = c;
				return *this;	
			}
			
			GameBuilder & year(int y) {
				_year = y;
				return *this;	
			}
	};
};

ostream & operator<<(ostream & output, Game arg) {
	output << arg.name << " by " << arg.company << " in " << arg.country << " (" << arg.year << ")";
	return output;
}

// Initialize static const data members
const string Game::GameBuilder::defaultName = "NOT_ASSIGNED";
const string Game::GameBuilder::defaultCompany = "NOT_ASSIGNED";
const string Game::GameBuilder::defaultCountry = "NOT_ASSIGNED";

int main() {
	// Use a builder to build ONE new product - have to create a new GameBuilder object every time
	Game Gunbound = Game::GameBuilder().name("Gunbound: Thor's Hammer").company("Softnyx").country("South Korea").year(2003).buildGame();
	Game SP = Game::GameBuilder().name("Survival Project: Search for the Legendary Orb").company("IO Entertainment").country("South Korea").year(2001).buildGame();
	Game MS = Game::GameBuilder().name("Maple Story").company("Nexon").country("South Korea").year(2003).buildGame();
	Game GunZ = Game::GameBuilder().name("GunZ: The Duel").company("Maiet Entertainment").country("South Korea").year(2003).buildGame();
	Game Dragonica = Game::GameBuilder().name("Dragonica").company("Barunson Interactive").country("Europe").year(2009).buildGame();
	Game CF = Game::GameBuilder().name("CrossFire").company("Smile Gate").country("South Korea").year(2007).buildGame();
	Game LoL = Game::GameBuilder().name("League Of Legends").company("Riot Games").country("United States").year(2009).buildGame();
	
	// Create a builder and use it to build MORE new products - create a GameBuilder object once and use that to create new Games
	Game::GameBuilder myGameBuilder;
	Game Seiken3 = myGameBuilder.name("Seiken Densetsu 3").company("Square").year(1995).country("Japan").buildGame();
	Game Chrono = myGameBuilder.name("Chrono Trigger").buildGame();
	Game Kirby = myGameBuilder.name("Kirby Superstar").company("Hal Laboratory").year(1996).buildGame();

	cout << Seiken3 << endl;
	cout << Chrono << endl;
	cout << Kirby << endl << endl;
	
	cout << Gunbound << endl;
	cout << SP << endl;
	cout << MS << endl;
	cout << GunZ << endl;
	cout << Dragonica << endl;
	cout << CF << endl;
	cout << LoL << endl;
}
