#include <iostream>
#include <string>
#include "Header.h"
#include "Definition.cpp"

template<typename T>
List<T> operator+(const List<T>& left, const List<T>&right)
{
	List<T> buffer = left;
	for (List<T>::Iterator it = right.begin(); it != right.end(); it++)
	{
		buffer.push_back(*it);
	}
	std::cout << "Global operator+\n";
	return buffer;
}
//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK
//#define OPERATORS+CHECK


void main()
{
#ifdef OPERATORS+CHECK
	int n;
	std::cout << "Input list size: "; //std::cin >> n;
#ifdef BASE_CHECK
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.print_revers();
	//std::cout << "____________________________add front___________________________________" << std::endl;
	//list.push_front(100);
	//list.print();
	//list.print_revers();
	//std::cout << "____________________________add back____________________________________" << std::endl;
	//list.push_back(200);
	//list.print();
	//list.print_revers();
	//std::cout << "__________________________delete front__________________________________" << std::endl;
	//list.pop_front();
	//list.print();
	//list.print_revers();
	//std::cout << "__________________________delete back___________________________________" << std::endl;
	//list.pop_back();
	//list.print();
	//list.print_revers();
	std::cout << "______________________________insert____________________________________" << std::endl;
	int index;
	int data;
	try
	{
		std::cout << "Input index: "; std::cin >> index;
		//	std::cout << "Intex value: "; std::cin >> data;
		list.erase(index);
		list.print();
		list.print_revers();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
#endif // BASE_CHECK
#ifdef CONSTRUCTORS_CHECK

	List list = { 3,5,8,13,21 };
	list = list;
	list.print();
	list.print_revers();

	List list2 = list;
	//list2= list;
	list2.print();
	list2.print_revers();
#endif // CONSTRUCTORS_CHECK


	int arr[] = { 3,5,8,13,21 };
	for (int i : arr) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;


	List list = { 3,5,8,13,21 };
	List list2 = { 34,55,89 };
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "___________________________________________\n";

	for (int i : list + list2)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	List list3;
	list3 = list + list2;
	list3.print();
	std::cout << "___________________________________________\n";

	for (List::ReverseIterator rit = list3.rbegin(); rit != list3.rend(); rit++)
	{
		std::cout << *rit << "\t";
	}
	std::cout << std::endl;
	std::cout << "___________________________________________\n";
#endif // OPERATORS+CHECK
	/*List<int> list1 = { 3,5,8,13,21 };
	for (List<int>::Iterator it = list1.begin(); it != list1.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	List<int> list2 = { 34,55,89 };
	for (int i:list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<int> list3 = list1 + list2;
	list3.print();
	for (int i : list3)
		std::cout << i << "\t";
	std::cout << std::endl;*/

	/*List<double> list1 = { 3.1,5.1,8.1,13.1,21.1 };
	for (double i : list1)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<double> list2 = { 34.1,55.1,89.1 };
	for (double i : list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<double> list3 = list1 + list2;
	list3.print();
	for (double i : list3)
		std::cout << i << "\t";
	std::cout << std::endl;
*/

	List<std::string> list1 = { "Number","one" };
	for (std::string i : list1)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<std::string> list2 = { "Number","two" };
	for (std::string i : list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<std::string> list3 = list1 + list2;
	list3.print();
	for (std::string i : list3)
		std::cout << i << "\t";
	std::cout << std::endl;



	//List<double> list2 = { 2.7,3.14,5.5};
	//for(double i:list2)
	//	std::cout<<i<<"\t";
	//std::cout << std::endl;

	//List<std::string> list3 = { "Hello","World!","How","are","you?" };
	//for (std::string i : list3)
	//{
	//	std::cout << i << "\t";
	//}
	//std::cout << std::endl;
}