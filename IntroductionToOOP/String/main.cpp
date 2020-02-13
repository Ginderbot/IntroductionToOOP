#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// CLASS DECLARATION /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

class String
{
	int size; //количество байт
	char* str;
public:
	const int get_size() const;
	const char* get_str() const;
	char* get_str();

	void set_str(const char* str);

	explicit String(int size = 90);
	String(const char* str);

	String(const String &other);
	~String();
	String& operator=(const String &other);
	const char& operator[](int i)const;

	char& operator[](int i);

	//  Metods
	void print();

};
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// CLASS DEFINITION //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

const int String::get_size() const
{
	return this->size;
}
const char* String::get_str() const
{
	return this->str;
}
char* String::get_str()
{
	return this->str;
}

void String::set_str(const char* str)
{
	delete[] this->str;
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	strcpy(this->str, str);
}

String::String(int size) : size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	std::cout << "DefaultConstructor:\t" << this << std::endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	std::cout << "Constructor:\t" << this << std::endl;
}
String::String(const String &other) : String(other.str)
{
	/*this->size = other.size;
	str = new char[size] {};
	strcpy_s(this->str, size, other.str);*/
	/*	for (int i = 0; i < size; i++)this->str[i] = other.str[i];*/
	std::cout << "CopyConstructor:\t" << this << std::endl;
}

String::~String()
{
	delete[] this->str;
	std::cout << "Destructor:\t" << this << std::endl;
}
//Operators
String& String::operator=(const String &other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	str = new char[size] {};
	strcpy_s(this->str, size, other.str);
	std::cout << "CopyAssigment:\t" << this << std::endl;
	return *this;
}
const char& String::operator[](int i) const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
//  Metods
void String::print()
{
	std::cout << size << "\t" << str << std::endl;
}

String operator+(const String &Left, const String &Right)
{
	String cat(Left.get_size() + Right.get_size() - 1);
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
bool operator==(const String& Left, const String& Right)
{
	if (strlen(Left.get_str()) != strlen(Right.get_str())) return false;
	for (int i = 0; Left[i]; i++)
	{
		if (Left[i] != Right[i]) return false;
	}
	return true;
}
bool operator!=(const String& Left, const String& Right)
{
	return !(Left == Right);
}
bool operator<(const String& Left, const String& Right)
{
	return strcmp(Left.get_str(), Right.get_str()) < 0 ? true : false;
}
bool operator>(const String& Left, const String& Right)
{
	return strcmp(Left.get_str(), Right.get_str()) > 0 ? true : false;
}
bool operator>=(const String& Left, const String& Right)
{
	return (Left > Right) || (Left == Right);
}
bool operator<=(const String& Left, const String& Right)
{
	return (Left < Right) || (Left == Right);
}
std::ostream& operator<< (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>> (std::istream& is, String& obj)
{
	char* sz_str = new char[USHRT_MAX] {};
	is >> sz_str;
	sz_str = (char*)realloc(sz_str, strlen(sz_str) + 1);
	obj.set_str(sz_str);
	delete[] sz_str;
	return is;
}

///////////////////////////////////////////////////////////////////////////////////////

//#define OPERATOR_PLUS_CHECK
//#define INPUT_CHECK

void main()
{
#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	str1.print();

	String str2 = "World!";
	str2.print();

	String str3 = str1 + str2;
	str3.print();
#endif // OPERATOR_PLUS_CHECK
#ifdef INPUT_CHECK
	String str = "Hello";
	//std::cout << "Input: ";
	std::cout << str << std::endl;
	std::cin >> str;
	std::cout << str << std::endl;
#endif // INPUT_CHECK

	String str1 = "Hello";
	String str2 = "World";
	std::cout << (str1 < str2) << std::endl;
}