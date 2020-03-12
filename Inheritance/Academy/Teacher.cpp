#include "Header.h"
Teacher::Teacher
(
	const std::string& last_name, const std::string& first_name, unsigned int age,
	const std::string& subject, unsigned int number_of_groups, unsigned int evil = 100
) : Human(last_name, first_name, age)
{
	set_subject(subject);
	set_number_of_groups(number_of_groups);
	set_evil(evil);
	std::cout << "TConstructor:\t" << this << std::endl;
}
Teacher::~Teacher()
{
	std::cout << "TDestructor:\t" << this << std::endl;
}
void Teacher::print()const
{
	Human::print();
	std::cout << "Предмет: " << subject << "\t";
	std::cout << "Количество груп: " << experience << "\t" << "Опит преподавания: " << evil << std::endl;
}