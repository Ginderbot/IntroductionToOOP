#include "Header.h"
Human::Human(const std::string& last_name, const std::string first_name, unsigned int age)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	std::cout << "HConstructor:\t" << this << std::endl;
}
Human::~Human()
{
	std::cout << "HDestructor:\t" << this << std::endl;
}
void Human::print()const
{
	std::cout.width(8);
	/*std::ios_base::left;*/
	std::cout /*<< "Фамилия: " */ << last_name << "\t";
	std::cout.width(8);
	std::cout /*<< "Имя: " */ << first_name << "\t";
	std::cout.width(8);
	std::cout /*<< "Возраст: "*/ << age << std::endl;
}