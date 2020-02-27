#include <iostream>
#include <regex>
#include <string>

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const unsigned int get_age()const
	{
		return age;
	}

	void set_last_name(const std::string& last_name)
	{
		std::regex exp ("\\w");
		this->last_name = last_name;

	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//  Constructors:

	Human(const std::string& last_name, const std::string first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}
	virtual ~Human()
	{
		std::cout << "HDestructor:\t" << this << std::endl;
	}

	virtual void print()const
	{
		std::cout.width(8);
		/*std::ios_base::left;*/
		std::cout /*<< "Фамилия: " */<< last_name << "\t";
		std::cout.width(8);
		std::cout /*<< "Имя: " */<< first_name << "\t";
		std::cout.width(8);
		std::cout /*<< "Возраст: "*/ << age << std::endl;
	}
};

class Student :public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string& get_specialty()const
	{
		return spec;
	}
	const std::string& get_group()const
	{
		return group;
	}
	unsigned int get_rating()const
	{
		return rating;
	}
	unsigned int get_attendence()const
	{
		return attendence;
	}

	void set_specialty(const std::string& spec)
	{
		this->spec = spec;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating <= 100 ? rating : 100;
	}
	void set_attendence(unsigned int attendence)
	{
		this->attendence = attendence <= 100 ? attendence : 100;
	}

	//    Constructor
	Student
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
	~Student()
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}

	void print()const
	{
		Human::print();
		std::cout << spec << "\t" << group << "\t" << "успеваемость " << rating << "%, посещаемость " << attendence << "%\n";
	}
};

class Teacher :public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	unsigned int get_number_of_groups()const
	{
		return experience;
	}
	unsigned int get_evil()const
	{
		return evil;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_number_of_groups(unsigned int number_of_groups)
	{
		this->experience = number_of_groups;
	}
	void set_evil(unsigned int evil)
	{
		this->evil = evil;
	}

	// Constructor
	Teacher
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
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}
	void print()const
	{
		Human::print();
		std::cout << "Предмет: " << subject << "\t";
		std::cout << "Количество груп: " << experience << "\t" << "Опит преподавания: " << evil << std::endl;
	}
};

class Graduate :public Student
{
	std::string topic;
	std::string curator;
	bool done;
public:
	const std::string& get_topic()const
	{
		return topic;
	}
	const std::string& get_curator()const
	{
		return curator;
	}
	bool get_done()
	{
		return done;
	}
private:
	void set_topic(const std::string& topic)
	{
		this->topic = topic;
	}
public:
	void set_curator(const std::string& curator)
	{
		this->curator = curator;
	}
	void set_done(bool done)
	{
		this->done = done;
	}

	// Constructor

	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
		const std::string& topic, const std::string& curator, bool done = 0
	) : Student(last_name, first_name, age, spec, group, rating, attendence)
	{
		set_topic(topic);
		set_curator(curator);
		set_done(done);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}
	void print()const
	{
		Student::print();
		std::cout << "Тема роботы: " << topic << "\t" << "Куратор:" << curator << "\t" << "Готовность: ";
		(done) ? std::cout << "Выполнено" : std::cout << "В процессе";
		std::cout << std::endl;
	}
};
//#define REGEX_NAME
#define REGEX_GROOP
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
		new Graduate("Колач","Геннадий",22,"РПО","СТ ПВ 35", 96,100,"Разработка игры для андроид", "Some Tetcher",1),
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
	std::cout << std::regex_match(name, rgx, std::regex_constants::match_default)<<std::endl;
#endif // REGEX_NAME
#ifdef REGEX_GROOP
	std::string groop;
	std::cout << "Input name ";/* std::cin >> groop;*/
	std::regex rgx("(ST|PS[ _\-](SB|VS))[ _\-](PU|PV|ITU|ITV|DU|DV)[_ \-]\\d{2}[abv]?");
	getline(std::cin, groop);
	std::regex rgx_replace(" |\-");
	groop=std::regex_replace(groop, rgx_replace, "_", std::regex_constants::match_default);
	std::cout << std::regex_match(groop, rgx, std::regex_constants::match_default) << std::endl;
	std::cout << groop << std::endl;
#endif REGEX_GROOP
}