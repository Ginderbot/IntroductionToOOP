#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;

static bool finich = false;

void Print_1()
{
	while (!finich)
	{
		std::cout << "1";
		std::this_thread::sleep_for(1s);
	}
}

void Print_2()
{
	while (!finich)
	{
		std::cout << "0";
		std::this_thread::sleep_for(1s);
	}
}

void main()
{
	//while (!finich)
	//{
	//	std::cout << "Hello";
	//}
	std::thread	thread_1(Print_1);
	std::thread	thread_2(Print_2);
	
	std::cin.get();
	finich = true;

	thread_2.join();
	thread_1.join();
}