#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<list>
#include<Windows.h>
#include <conio.h>
#include"boost/algorithm/string.hpp"

std::map<std::string, std::list<std::string>> init();
void print_full_base(const std::map<std::string, std::list<std::string>>& base);
void save(const std::map<std::string, std::list<std::string>>& base);
void load(std::map<std::string, std::list<std::string>>& base);
void insert(std::map<std::string, std::list<std::string>>& base);
void menu();
int choice(int iterator);
void find(std::map<std::string, std::list<std::string>>& base);

void main()
{
	setlocale(LC_ALL, "");
	//std::map<std::string, std::list<std::string>> base;// = init();
	//std::map<std::string, std::list<std::string>> base = init();
	//load(base);
#define delimiter "\n------------------------------------\n"
	/*print_full_base(base);
	insert(base);
	print_full_base(base);
	save(base);*/
	menu();
}

void menu()
{
	int iterator = 1;
	std::map<std::string, std::list<std::string>> base = init();
	do
	{
		iterator = choice(iterator);
	} while (getch() != 13);
	if (iterator == 1)
	{
		load(base);
	}
	else if (iterator == 2)//сохранение базы в файл
	{
		save(base);
	}
	else if (iterator == 3)//вывод базы на екран
	{
		print_full_base(base);
	}
	else if (iterator == 4)//вывод правонарушений по указанному номеру
	{
		find(base);
	}
}

void find(std::map<std::string, std::list<std::string>>& base)
{
	std::string license_plate;

	std::cout << "Введите номер автомобиля: ";
	SetConsoleCP(1251);	std::getline(std::cin, license_plate);	SetConsoleCP(866);

	//std::map<std::string, std::list<std::string>>::iterator offender = base.find(license_plate);
	std::cout << license_plate << " - ";
	for (std::list<std::string>::iterator it = base.find(license_plate)->second.begin(); it != base.find(license_plate)->second.end(); it++)
	{
		std::cout << *it << ",";
	}
	std::cout << "\b;\n";
}

int choice(int iterator)
{
	int choice = getch();
	system("cls");
	std::cout << choice << std::endl;
	if (choice == 224)choice = getch();
	if (choice == 72)
	{
		if (iterator > 1)iterator--;
		else iterator = 4;
	}
	else if (choice == 80/*choice==224*/)
	{
		if (iterator < 4)iterator++;
		else iterator = 1;
	}
	else if (choice != 13) std::cout << "Неверный ввод" << std::endl;
	else
	{
		std::cout << "Error";
	}

	std::cout << "Сделайте Ваш выбор: " << std::endl;
	(iterator == 1) ? std::cout << "==>" : std::cout << "   ";
	std::cout << "Загрузка базы из файла" << std::endl;
	(iterator == 2) ? std::cout << "==>" : std::cout << "   ";
	std::cout << "Сохранение базы в файл" << std::endl;
	(iterator == 3) ? std::cout << "==>" : std::cout << "   ";
	std::cout << "Вывод базы на экран" << std::endl;
	(iterator == 4) ? std::cout << "==>" : std::cout << "   ";
	std::cout << "Вывод правонарушений по указанному номеру" << std::endl;
	std::cout << delimiter;
	return{ iterator };
};

std::map<std::string, std::list<std::string>> init()
{
	std::map<std::string, std::list<std::string>> base =
	{
		std::pair<std::string, std::list<std::string>>("BI 0000 BI",{ "Привышение скорости","Вождение в нетрезвом состоянии" }),
		std::pair<std::string, std::list<std::string>>("BI 0001 BI",{ "Езда по встречке" }),
		std::pair<std::string, std::list<std::string>>("BI 0002 BI",{ "Парковка в неположеном месте" }),
		std::pair<std::string, std::list<std::string>>("BI 0003 BI",{ "Проезд на красный","Привышение скорости","Плюнул в полицейского" })
	};
	return base;
}

void print_full_base(const std::map<std::string, std::list<std::string>>& base)
{
	/*for (std::map<std::string, std::list<std::string>>::iterator m_it = base.begin(); m_it != base.end(); m_it++)
	{
	std::cout << m_it->first << ":\n";
	for (std::list<std::string>::iterator l_it = m_it->second.begin(); l_it != m_it->second.end(); l_it++)
	{
	std::cout << " - " << l_it->c_str() << ";\n";
	}
	std::cout << delimiter;
	}*/

	/*int arr[] = { 3,5,8,13,21 };
	for (int i : arr)
	{
	std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;*/

	for (std::pair<std::string, std::list<std::string>> i : base)
	{
		std::cout << i.first << ":\n";
		for (std::string j : i.second)
		{
			std::cout << " - " << j << ";\n";
		}
		std::cout << delimiter;
	}
}

void save(const std::map<std::string, std::list<std::string>>& base)
{
	bool check = false;
	std::ofstream fout("base.txt");
	//CSV - Comma Separated values;
	for (std::pair<std::string, std::list<std::string>> i : base)
	{
		if(check)fout << "\n";
		fout << i.first << ":";
		for (std::string j : i.second)
		{
			fout << j << ",";
		}
		fout.seekp(-1, std::ios::cur); //сдвинуть курсор на позицию -1
		fout << ";";
		check = true;
	}

	fout.close();
	system("start notepad base.txt");
}

void load(std::map<std::string, std::list<std::string>>& base)
{
	base.clear();
	std::string license_plate;
	std::string violation;
	std::list<std::string> violation_list;

	std::ifstream fin("base.txt");

	if (fin.is_open())
	{
		//std::istream& stream = fin;
		//fin.seekg(0, std::ios::beg);
		while (!fin.eof())
		{
			//fin.getline(license_plate.c_str(), 20, ":");
			std::getline(fin, license_plate, ':');
			if (license_plate == "")break;
			std::getline(fin, violation, ';');
			std::cout << license_plate << "-" << violation << std::endl;

			boost::algorithm::split(violation_list, violation, boost::is_any_of(","));
			//base.insert(std::pair<std::string, std::list<std::string>>(license_plate, violation_list));

			//for (std::string i : violation_list);


			// print_full_base(base);
			//system("PAUSE");
		}
	}
	else
	{
		std::cerr << "Error: file not found" << std::endl;
	}

	fin.close();
}

void insert(std::map<std::string, std::list<std::string>>& base)
{
	std::string license_plate;
	std::string violation;

	std::cout << "Введите номер автомобиля: "; //std::cin >> license_plate;
	SetConsoleCP(1251);	std::getline(std::cin, license_plate);	SetConsoleCP(866);

	std::cout << "Введите правонарушение: "; //std::cin >> violation;
	SetConsoleCP(1251);	std::getline(std::cin, violation);		SetConsoleCP(866);

	if (license_plate.size() == 0 || violation.size() == 0)return;

	std::map<std::string, std::list<std::string>>::iterator offender = base.find(license_plate);
	if (offender != base.end())
	{
		//Если номер есть в базе то добавляем нарушение к существующему номеру
		offender->second.push_back(violation);
	}
	else
	{
		//Создаем нового нарушителя в базу
		base.insert(std::pair<std::string, std::list<std::string>>(license_plate, { violation }));
	}
}