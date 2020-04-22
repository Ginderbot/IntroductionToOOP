#include<iostream>
#include<string>
#include<map>
#include<list>
#include<fstream>

std::map<std::string, std::list<std::string>> init();
void print_full_base(std::map<std::string, std::list<std::string>>&base);
void save(std::map<std::string, std::list<std::string>>&base);
void load(std::map<std::string, std::list<std::string>>&base);
void insert(std::map<std::string, std::list<std::string>>&base);

void main()
{
	setlocale(LC_ALL, "");
	std::map<std::string, std::list<std::string>>base = init();
#define delimiter "__________________________________\n\n"
	print_full_base(base);
	save(base);
	system"start notepad base.txt";
}
std::map<std::string, std::list<std::string>> init()
{
	std::map<std::string, std::list<std::string>>base =
	{ 
		std::pair < std::string, std::list<std::string>>
		("BI 0000 BI", { "Привышение скорости","Вождение в нетрезвом состоянии" }),

		std::pair < std::string, std::list<std::string>>
		("BI 0001 BI", { "Езда по встречке" }),

		std::pair < std::string, std::list<std::string>>
		("BI 0002 BI", { "Парковка в неположеном месте" }),

		std::pair < std::string, std::list<std::string>>
		("BI 0003 BI", { "Проезд на красный","Привышение скорости","Плюнул в полицейского" });
	};
	return std::map<std::string, std::list<std::string>>base;
}
void print_full_base(std::map<std::string, std::list<std::string>>&base)
{
	//for (std::map<std::string, std::list<std::string>>::iterator m_it=base.begin();m_it!=base.end();m_it++)
	//{
	//	std::cout << m_it->first << ":\n";
	//	for (std::list<std::string>::iterator l_it=m_it->second.begin();l_it!=m_it->second.end();l_it++)
	//	{
	//		std::cout << " - " << l_it->c_str() << ";\n";
	//	}
	//	std::cout << delimiter;
	//}
	for (std::pair < std::string, std::list<std::string>> i : base)
	{
		std::cout << i.first << ":\n";
		for (std::string j : i.second)
		{
			std::cout << j << "\n";
		}
		std::cout << delimiter;
	}
}
void save(std::map<std::string, std::list<std::string>>&base)
{
	std::ofstream fout("base.txt");

	for (std::pair < std::string, std::list<std::string>> i : base)
	{
		fout << i.first << ": ";
		for (std::string j : i.second)
		{
			fout << j << ", ";
		}
		fout.seekp(-2, std::ios::cur);//сдвинуть курсор на позицию -2
		fout << ";\n";
	}
	fout.close();
	system("notepad base.txt");
}
void load(std::map<std::string, std::list<std::string>>&base)
{
	base.clear();
	std::string license_plate;
	std::list<std::string>violation_list;

	std::ifstream fin("base.txt");

	if (fin.is_open())
	{
		//std::istream& stream = fin;
		while (!fin.eof())
		{
			//fin.getline(license_plate.c_str(), 20, ":");
			std::getline(fin, license_plate, ':');
			std::
		}
	}
	else
	{
		std::cerr << "Error: file not found" << std::endl;
	}

	fin.close();

}
void insert(std::map<std::string, std::list<std::string>>&base)
{
	std::string license_plate;
	std::string violation;
	std::cout << "Введите номер автомобиля: ";// std::cin >> license_plate;
	
	std::cout << "Введите правонарушение: ";// std::cin >> violation;

	if(license_plate)

	std::map<std::string, std::list<std::string>>::iterator offender = base.find(license_plate);
	if (offender != base.end())
	{
		//Если номер есть в базе то добавляем нарушение к существующему номеру
		offender->second.push_back(violation);
	}
	else
	{
		//Создаем нового нарушителя в базу
		base.insert(std::pair<std::string, std::list<std::string>>(license_plate, { violation }))
	}
}
