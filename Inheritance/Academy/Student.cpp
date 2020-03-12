#include "Header.h"

Student::Student
(
	const std::string& last_name, const std::string& first_name, unsigned int age,
	const std::string& spec, const std::string group, unsigned int rating = 0, unsigned int attendence = 0
) :Human(last_name, first_name, age)
{
	set_specialty(spec);
	set_group(group);
	set_rating(rating);
	set_attendence(attendence);
	std::cout << "SConstructor:\t" << this << std::endl;
}

Student::~Student()
{
	std::cout << "SDestructor:\t" << this << std::endl;
}

void Student::print()const
{
	Human::print();
	std::cout << spec << "\t" << group << "\t" << "успеваемость " << rating << "%, посещаемость " << attendence << "%\n";
}