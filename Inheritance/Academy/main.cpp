#include "Class.h"

//#define POLIMORPHISM
void main()
{
	setlocale(LC_ALL, "");
	/*Human human("Тупенко", "Василь", 18);
	human.print();

	Student stud("Тупенко", "Василь", 18, "Дизайн", "СТ ДВ 37");
	stud.print();

	Teacher teach("Енштейн", "Альберт", 141, "Астрономия", 20);
	teach.print();

	Graduate grad(
		"Иванченко", "Иван", 21,
		"Дизайн", "СТ ДВ 37", 95, 34,
		"Смысл жизни", "Петренко");
	grad.print();*/

#ifdef POLIMORPHISM
	Human* groop[] =
	{
		new Student("Ковальчук","Антон",15,"РПО","СТ ПВ 35", 95,100),
		new Student("Кравцов","Артём",15,"РПО","СТ ПВ 35", 85,97),
		new Teacher("Кобылинский","Андрей",42,"Hurdware&Windows", 5, 0),
		new Student("Горбенко","Богдан",16,"РПО","СТ ПВ 35", 99,100),
		new Graduate("Маслак","Михаил",17,"РПО","СТ ПВ 35", 95,100,"3D Shooter development", "О.А."),
		new Teacher("Котун","Олег",35,"С++", 5, 32),
		new Graduate("Колач","Геннадий",21,"РПО","СТ ПВ 35", 96,100,"Разработка игры для андроид", "Some Tetcher",1),
	};

	for (int i = 0; i < sizeof(groop) / sizeof(Human*); i++)
	{
		std::cout << "\n----------------------------------------------------------------------------------------------\n";
		groop[i]->print();
	}
	for (int i = 0; i < sizeof(groop) / sizeof(Human*); i++)
	{
		delete groop[i];
	}
	std::cout << "\n----------------------------------------------------------------------------------------------\n";
#endif // POLIMORPHISM
	std::string name;
	std::cout << "Input name "; std::cin >> name;
	std::regex rgx("[A-Z][a-z]{1,19}");
	std::cout << std::regex_match(name, rgx, std::regex_constants::match_default)<<std::endl;


}