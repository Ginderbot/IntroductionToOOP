#include "Class.h"

//#define POLIMORPHISM
void main()
{
	setlocale(LC_ALL, "");
	/*Human human("�������", "������", 18);
	human.print();

	Student stud("�������", "������", 18, "������", "�� �� 37");
	stud.print();

	Teacher teach("�������", "�������", 141, "����������", 20);
	teach.print();

	Graduate grad(
		"���������", "����", 21,
		"������", "�� �� 37", 95, 34,
		"����� �����", "��������");
	grad.print();*/

#ifdef POLIMORPHISM
	Human* groop[] =
	{
		new Student("���������","�����",15,"���","�� �� 35", 95,100),
		new Student("�������","����",15,"���","�� �� 35", 85,97),
		new Teacher("�����������","������",42,"Hurdware&Windows", 5, 0),
		new Student("��������","������",16,"���","�� �� 35", 99,100),
		new Graduate("������","������",17,"���","�� �� 35", 95,100,"3D Shooter development", "�.�."),
		new Teacher("�����","����",35,"�++", 5, 32),
		new Graduate("�����","��������",21,"���","�� �� 35", 96,100,"���������� ���� ��� �������", "Some Tetcher",1),
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