#include <iostream>
#include <thread>
#include <list>
#include <mutex>

using namespace std;

list<int> myList;
std::mutex mx;

void addToList(int max, int interval)
{
	std::lock_guard<std::mutex> guard(mx);
	for (int i = 0; i <= max; i++)
	{
		if ((i % interval) == 0)
		{
			myList.push_back(i);
		}
	}
}

void printList()
{
	std::lock_guard<std::mutex> guard(mx);
	for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; itr++)
	{
		cout << *itr << ", ";
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	int max = 100;
	thread T1(addToList, max, 1);
	thread T2(addToList, max, 10);
	thread T3(printList);

	T1.join();
	T2.join();
	T3.join();

	return 0;
}