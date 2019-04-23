#include <iostream>
#include <map>

using namespace std;

struct cmp_str
{
	bool operator() (string a, string b)
	{
		//Normal behaviour: 1 in case, that second agument is greater than first one
		//return (b > a) ? 1 : 0;

		//Different order
		return (b < a) ? 1 : 0;
	}
};

int main(int argc, char *argv[])
{
	int reti = 0;

	//Map - sorting is ruled by strings
	//map <string, int> sth;

	//Map - sorting is defined in function cmp_str
	map <string, int, cmp_str> sth;

	sth["String"] = 7;
	sth["AnotherString"] = 13;

	sth.insert(pair<string, int>("NewString", 11));
	sth.insert(make_pair("SomeString", 9));
	sth.insert(map<string, int>::value_type("DifferentString", 5));

	cout << "Size of container: " << sth.size() << endl;
	cout << "Allocated size of container: " << sth.max_size() << endl;
	map<string, int>::iterator i;


	for (i = sth.begin(); i != sth.end(); i++)
	{
		cout << (*i).first << ":" << (*i).second << endl;
	}

	cout << endl << endl;
	i = sth.find("DifferentString");
	sth.erase(i);
	for (i = sth.begin(); i != sth.end(); i++)
	{
		cout << (*i).first << ":" << (*i).second << endl;
	}

	return reti;
}