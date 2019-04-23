#include <iostream>
#include <map>

using namespace std;

class Person
{
private:
	friend class ComparePerson;
public:
	string name;
	string surname;
	Person(string name, string surname) : name(name), surname(surname) {}
};

struct ComparePerson
{
	bool operator() (Person a, Person b)
	{
		return (b.surname > a.surname) ? 1 : 0;
	}
};

int main(int argc, char *argv[])
{
	int reti = 0;

	//Custom class map
	map <Person, bool, ComparePerson> people;
	Person P1("Name1", "Surname1");
	Person P2("Name2", "Surname2");

	people[P2] = true;
	people[P1] = false;

	map<Person, bool, ComparePerson>::iterator i;
	for (i = people.begin(); i != people.end(); i++)
	{
		cout << i->first.name << "   " << i->first.surname << "   " << i->second << endl;
	}


	return reti;
}