
#include <iostream>
#include <thread>
#include <condition_variable>

using namespace std;

mutex mx;
condition_variable cv;
bool dataReady;

void outputfcn()
{
	cout << "Waiting for data" << endl;
	unique_lock<mutex> lck(mx);
	cv.wait(lck, []() {return dataReady; });
	cout << "Output" << endl;
}

void inputfcn()
{
	{
		lock_guard<mutex> lxk(mx);
		dataReady = true;
	}
	cout << "Data ready" << endl;
	cv.notify_one(); //Alternative: notify_all() - all threads will continue
}

int main(int argc, char *argv[])
{
	cout << "Begin" << endl;

	thread TO(outputfcn);
	thread TI(inputfcn);

	TI.join();
	TO.join();




	cout << "End" << endl;


	return 0;
}