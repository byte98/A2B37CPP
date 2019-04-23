#include <iostream>
#include <mutex>
#include <thread>

std::mutex mu;
void shared_cout(std::string msg, int id)
{
	mu.lock();
	std::cout << msg << ":" << id << std::endl;
	mu.unlock();
}

void thread_function()
{
	for (int i = -100; i < 0; i++)
	{
		shared_cout("Thread function", i);
	}
}

int main(int argc, char *argv[])
{
	std::thread t(&thread_function);
	for (int i = 100; i > 0; i--)
	{
		std::cout << "Main function: " << i << std::endl;
	}
	t.join();
	return 0;
}