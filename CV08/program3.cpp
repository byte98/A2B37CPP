#include <iostream>
#include <vector>

using namespace std;
class Item
{
	//Base class, describes interface to items, fully virtual
public:
	virtual void create() {}; //Method to create item
	virtual void print() {}; //Method to print item
	virtual void findName() {}; //Method to find item by author name
};

class Book : public Item
{
private:
	string name;
public:
	Book(string name = " ") : name(name) { create(); };
	void create()
	{
		cout << "Book created" << endl;
	}
	void print()
	{
		cout << "Book: " << this->name << endl;
	}
	void findName()
	{
		cout << "Searching by name" << endl;
	}
};

class Journal : public Item
{
private:
	string name;
public:
	Journal(string name = " ") : name(name) { create(); };
	void create()
	{
		cout << "Journal created" << endl;
	}
	void print()
	{
		cout << "Journal: " << this->name << endl;
	}
	void findName()
	{
		cout << "Journal hasn't got one author only..." << endl;
	}
};

class Database
{
private:
	vector<Item*> data;
public:
	Database() {};

	void add(Item *item)
	{
		this->data.push_back(item);
	}
	void find()
	{
		for (unsigned int i = 0; i < this->data.size(); i++)
		{
			this->data[i]->findName();
		}
	}
	void list()
	{
		for (unsigned int i = 0; i < this->data.size(); i++)
		{
			this->data[i]->print();
		}
	}
};

int main(int argc, char *argv[])
{
	int reti = 0;

	Database db;
	db.add(new Book("SomeBook1"));
	db.add(new Book("SomeBook2"));
	db.add(new Book("SomeBook3"));
	db.add(new Journal("SomeJournalOne"));
	db.add(new Journal("SomeJurnalTwo"));
	db.add(new Journal("SomeJournalThree"));
	db.list();
	db.find();

	cout << endl;

	cout << typeid(db).name() << endl;
	
	Book b;
	cout << typeid(b).name() << endl;

	Journal j;
	cout << typeid(j).name() << endl;

	vector<Item*> database2;
	database2.push_back(new Book("AnotherBook1"));
	database2.push_back(new Journal("AnotherJournal1"));
	

	cout << typeid(database2).name() << endl;
	cout << typeid(database2[0]).name() << endl;
	cout << typeid(static_cast<Journal*>(database2[1])).name() << endl;
	return reti;
}