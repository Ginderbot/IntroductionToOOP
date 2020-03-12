#include "Header.h"

//#define POLIMORPHISM
//#define REGEX_NAME
#define REGEX_GROOP
//#define REGEX_EMAIL
//#define REGEX_PHONE
//#define CONVERT_PHONE
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
		new Graduate("������","������",17,"���","�� �� 35", 95,100,"3D Shooter development", "�.�.",false),
		new Teacher("�����","����",35,"�++", 5, 32),
		new Graduate("�����","��������",22,"���","�� �� 35", 96,100,"���������� ���� ��� �������", "Some Tetcher",1),
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
#ifdef REGEX_NAME
	std::string name;
	std::cout << "Input name "; std::cin >> name;
	std::regex rgx("[A-Z][a-z]{1,19}");
	std::cout << std::regex_match(name, rgx, std::regex_constants::match_default) << std::endl;
#endif // REGEX_NAME
#ifdef REGEX_GROOP
	std::string groop;
	std::cout << "Input name ";/* std::cin >> groop;*/
	std::regex rgx("(ST|PS[ _\-](SB|VS))[ _\-](PU|PV|ITU|ITV|DU|DV)[_ \-]\\d{2}[abv]?");
	getline(std::cin, groop);
	std::regex rgx_replace(" |\-");
	groop = std::regex_replace(groop, rgx_replace, "_", std::regex_constants::match_default);
	std::cout << std::regex_match(groop, rgx, std::regex_constants::match_default) << std::endl;
	std::cout << groop << std::endl;
#endif REGEX_GROOP
#ifdef REGEX_EMAIL
	std::string email = "vasya@gmail.jks.uaa";
	/*std::cout << "Input E-mail: "; std::cin >> email;*/
	std::regex rgx("\\w{3,50}@[a-z]{1,20}[.][a-z]{2,3}(.[a-z]{2,3})?");
	std::cout << std::regex_match(email, rgx, std::regex_constants::match_default) << std::endl;
#endif // REGEX_EMAIL
#ifdef REGEX_PHONE
	std::string phone = "+38(099)123-45-67";
	//std::regex rgx("\\+\\d{2}\\([0]\\d{2}\\)\\d{3}(-\\d{2}){2}");
	std::regex rgx(R"(\+\d{2}\([0]\d{2}\)\d{3}(-\d{2}){2})");
	std::cout << std::regex_match(phone, rgx, std::regex_constants::match_default) << std::endl;
#endif // REGEX_PHONE
#ifdef CONVERT_PHONE
	 std::string phone = "380991234567";
	std::regex rgx("\\d{12}");
	if (std::regex_match(phone, rgx, std::regex_constants::match_default))
	{
		phone.insert(0, "+");
		phone.insert(phone.size() - 10, "(");
		phone.insert(phone.size() - 7, ")");
		phone.insert(phone.size() - 4, "-");
		phone.insert(phone.size() - 2, "-");
	}
		std::cout << phone << std::endl;
#endif // CONVERT_PHONE

}