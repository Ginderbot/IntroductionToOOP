#include <iostream>


class String
{
	int size; //количество байт
	char* str;
public:
	int get_size() const
	{
		return this->size;
	}
	const char* get_str() const
	{
		return this->str;
	}
	char* get_str()
	{
		return this->str;
	}
	/*void set_size()
	{
		this->size = size;
	}
	void set_str() const
	{
		this->str = str;
	}*/

	String(int size = 90)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String &other)
	{
		this->size = other.size;
		str = new char[size] {};
		strcpy_s(this->str, size, other.str);
		/*	for (int i = 0; i < size; i++)this->str[i] = other.str[i];*/
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}

	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}
	String& operator=(const String &other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		str = new char[size] {};
		strcpy_s(this->str, size, other.str);
		std::cout << "CopyAssigment:\t" << this << std::endl;
		return *this;
	}
	const char& operator[](int i) const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//  Metods
	void print()
	{
		std::cout << size << "\t" << str << std::endl;
	}

};
std::ostream& operator<< (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String &Left, const String &Right)
{
	String cat = Left.get_size() + Right.get_size() - 1;
	for (int i = 0; i < Left.get_size(); i++)
	{
		cat[i] = Left[i];
	}
	for (int i = 0; i < Right.get_size(); i++)
	{
		cat[i + Left.get_size() - 1] = Right[i];
	}
	return cat;
}

void main()
{
	String str1 = "Hello";
	str1.print();

	String str2 = "World!";
	str2.print();

	String str3 = str1 + str2;
	str3.print();

	/*std::cout << str3 << std::endl;*/
}