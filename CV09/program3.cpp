#include <thread>
#include <iostream>

class MyFunctor
{
public:
	void operator() ()
	{
		std::cout << "Functor here!" << std::endl;
	}
};


int main(int argc, char *argv[])
{
	MyFunctor functor;
	std::thread t(functor);
	std::cout << "Main thread is working." << std::endl;
	t.join();

	return 0;
}