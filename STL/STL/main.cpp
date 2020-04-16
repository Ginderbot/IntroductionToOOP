#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
#include <cstring>
#include<string>
#include<map>

//#define ARRAY
//#define VECTOR
//#define DEQUE
//#define FORWARD_LIST
const int SIZE = 5;

#ifdef ARRAY
void print(const std::array<int, SIZE>&arr)
{
	for (std::array<int, SIZE>::const_iterator it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
}
#endif // ARRAY

void main()
{
#ifdef ARRAY
	//array - это контейнер который хранит объекты в статическом массиве

	std::array<int, SIZE>arr{ 3,5,8 };
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
	for (std::array<int, SIZE>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	for (std::array<int, SIZE>::reverse_iterator rit = arr.rbegin(); rit != arr.rend(); rit++)
	{
		std::cout << *rit << "\t";
	}
	std::cout << std::endl;
	print(arr);
#endif // ARRAY

#ifdef VECTOR
	//vector - контейнер который хранит данные в виде динамического массива	
	std::vector<int> vec{ 0,1,1,2,3,5,8,12,21,34 };
	vec.push_back(55);

	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			//std::cout << vec[i] << "\t";
			std::cout << vec.at(i) << "\t";
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "vector size: " << vec.size() << std::endl;
	vec.shrink_to_fit();
	std::cout << "vector capacity: " << vec.capacity() << std::endl;
	std::cout << "vector max size: " << vec.max_size() << std::endl;

	int value;
	int index;
	std::cout << "type value: "; std::cin >> value;
	std::cout << "type index: "; std::cin >> index;
	//std::vector<int>::iterator position = vec.begin() + index;
	//vec.insert(position,value);
	vec.insert(vec.begin() + index, 3, value);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
#endif // VECTOR

#ifdef DEQUE
	std::deque<int> de{ 3,5,8,13 };
	de.push_front(0);
	de.push_front(1);
	de.push_front(1);
	de.push_front(2);
	for (int i : de)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
#endif // DEQUE

#ifdef FORWARD_LIST
	std::forward_list<int> list = { 3,5,8,13,21 };
	/*for (int i = 0; i < 5; i++)
	{
	//МЕДЛЕННО!
		std::cout << list[i] << "\t";
	}*/
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	int index, value;
	std::cout << "type index: "; std::cin >> index;
	std::cout << "type value: "; std::cin >> value;
	std::forward_list<int>::const_iterator position=list.begin();
	for (int i=0;i<index-1;i++)
	{
		position++;
	}
	list.insert_after(position, value);
	for (int i : list)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
#endif // FORWARD_LIST


	std::string number;
	std::cout << "Input number car: "; std::cin >> number;
	int money;
	std::cout << "Input money: "; std::cin >> money;

	std::map<std::string, int> baza;
	baza.emplace("BI8888AA", 200);

	try
	{
		int buff=money+baza.at(number);
		baza[number]=buff;
	}
	catch (const std::exception&ex)
	{
		baza.emplace(number, money);
	}
	std::cout << baza["BI8888AA"] << std::endl;
	std::cout << baza["BI0000AA"] << std::endl;
}