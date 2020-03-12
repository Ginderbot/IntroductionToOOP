#include "Header.h"
Graduate::Graduate
(
	const std::string& last_name, const std::string& first_name, unsigned int age,
	const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
	const std::string& topic, const std::string& curator, bool done=0
) : Student(last_name, first_name, age, spec, group, rating, attendence)
{
	set_topic(topic);
	set_curator(curator);
	set_done(done);
	std::cout << "GConstructor:\t" << this << std::endl;
}
Graduate::~Graduate()
{
	std::cout << "GDestructor:\t" << this << std::endl;
}
void Graduate::print()const
{
	Student::print();
	std::cout << "Тема роботы: " << topic << "\t" << "Куратор:" << curator << "\t" << "Готовность: ";
	(done) ? std::cout << "Выполнено" : std::cout << "В процессе";
	std::cout << std::endl;
}