#include <iostream>


class String
{
	int size; //количество байт
	char* str;
public:
	String(int size=90)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String &other)
	{
		this->size = other.size;
		str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}
	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}
	//  Metods
	void print()
	{
		std::cout << size << "\t" << str << std::endl;
	}

};

void main()
{
	String str1;
	str1.print();
	String str2 = "Hello";
	str2.print();

	String str3 = str2;
	str3.print();
}