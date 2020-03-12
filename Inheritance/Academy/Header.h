#pragma once
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
		std::regex exp("\\w");
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

	Human(const std::string& last_name, const std::string first_name, unsigned int age);
	virtual ~Human();
	virtual void print()const;
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
		const std::string& spec, const std::string group, unsigned int rating, unsigned int attendence
	);
	~Student();
	void print()const;
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
		const std::string& subject, unsigned int number_of_groups, unsigned int evil
	);
	~Teacher();
	void print()const;
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
		const std::string& topic, const std::string& curator, bool done
	);
	~Graduate();
	void print()const;
};