#include <iostream>

class Fraction
{
	int intager;
	int numerator;
	int denominator;
public:
	int get_integer(int integer) const
	{
		return this->intager;
	}
	int get_numerator(int numerator) const
	{
		return this->numerator;
	}
	int get_denominator(int denominator)const
	{
		return this->denominator;
	}
	void set_intager(int intager)
	{
		this->intager;
	}
	void set_numerator(int numerator)
	{
		this->numerator;
	}
	void set_denominator(int denominator)
	{
		//(denominator) ? this->denominator = denominator : this->denominator = 1;
		this->denominator = denominator ? denominator : throw std::exception("F^ck");
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Fraction A;
	try
	{
		A.set_intager(2);
		A.set_numerator(3);
		A.set_denominator(0);
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}