#include <iostream>
#include <thread>


void thread_function()
{
	std::cout << "Thread function is alive!\n";
}

int main(int argc, char *argv[])
{
	std::thread t(&thread_function);
	std::cout << "Main thread is working.\n";
	t.join(); // Main threads wait, till t thread is done.

	/*
	 * Thread can be run as stand alone process (deamon)
	 * by calling t.detach(). Cannot be cmbined with join()
	 * 
	 */

	return 0;
}