#include <iostream>

#define OPERATORS_CHECK
#define TYPE_CONVERTION
class Fraction
{
	int intager;
	int numerator;
	int denominator;
public:
	int get_intager() const // целое
	{
		return this->intager;
	}
	int get_numerator() const // числитель
	{
		return this->numerator;
	}
	int get_denominator()const // делитель
	{
		return this->denominator;
	}
	void set_intager(int intager)
	{
		this->intager = intager;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		//(denominator) ? this->denominator = denominator : this->denominator = 1;
		this->denominator = denominator ? denominator : throw std::exception("F^ck");
	}

	Fraction(const Fraction& other)
	{
		this->intager = other.intager;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}

	//		Assignments:

	Fraction& operator=(const Fraction& other)
	{
		this->intager = other.intager;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}
	Fraction& operator*=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		this->to_proper();
		this->yes();
		return *this;
	}
	Fraction& operator/=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator *= other.denominator;
		this->denominator *= other.numerator;
		this->to_proper();
		this->yes();
		return *this;
	}
	Fraction& operator-=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		(this->numerator *= other.denominator) -= this->denominator*other.numerator;
		this->denominator *= other.denominator;
		this->to_proper();
		this->yes();
		return *this;
	}
	Fraction& operator+=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		(this->numerator *= other.denominator) += this->denominator*other.numerator;
		this->denominator *= other.denominator;
		this->to_proper();
		this->yes();
		return *this;
	}
	Fraction& operator ++()
	{
		this->intager++;
		return *this;
	}
	Fraction operator ++(int)
	{
		Fraction temp = *this;
		this->intager++;
		return temp;
	}
	Fraction& operator --()
	{
		this->intager--;
		return *this;
	}
	Fraction operator --(int)
	{
		Fraction temp = *this;
		this->intager--;
		return temp;
	}

	//		Constructors:
	Fraction()
	{
		this->intager = 0;
		this->numerator = 0;
		this->denominator = 1;

		std::cout << "DefaultConstrucct:\t" << this << std::endl;
	}
	explicit Fraction(int intager)
	{
		this->intager = 0;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "SinglArgConstruct" << this << std::endl;
	}
	/*Fraction(double decimal)
	{
		this->intager = 0;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "SinglArgConstruct" << this << std::endl;
	}*/
	Fraction(int numerator, int denominator)
	{
		this->set_intager(0);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		std::cout << "Constructor:\t" << this << std::endl;
	}
	Fraction(int intager, int numerator, int denominator)
	{
		this->set_intager(intager);
		this->set_numerator(numerator);
		this->set_denominator(denominator);

		std::cout << "Constructor:\t" << this << std::endl;
	}
	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
	explicit operator int()
	{
		return this->intager;
	}
	explicit operator double()
	{
		return (double)this->numerator / this->denominator + this->intager;
	}
	//explicit operator Fraction()
	//{
	//	Fraction temp;
	//	while (? > 0)
	//	{
	//		temp.set_intager++;
	//		? --;
	//	}
	//	while (? *10 > 0)
	//	{
	//		? *10;
	//		temp.set_numerator *= 10 + ? ;
	//		if (temp.get_denominator < 1)
	//		{
	//			temp.set_denominator = 1;
	//		}
	//		temp.set_denominator *= 10;
	//		? -= (int) ? ;
	//	}
	//}
	void print() const
	{
		if (intager)
		{
			std::cout << intager;
		}
		if (numerator)
		{
			if (intager)std::cout << "(";
			std::cout << numerator << "/" << denominator;
			if (intager)std::cout << ")";
		}
		if (intager == 0 && numerator == 0)std::cout << 0;
		std::cout << std::endl;
	}

	void to_proper()
	{
		intager += numerator / denominator;
		numerator %= denominator;
	}

	void to_improper()
	{
		numerator += intager * denominator;
		intager = 0;
	}
	void yes()
	{
		bool plus = false;
		(numerator < 0) ? numerator -= numerator * 2 : plus = true;
		(denominator < 0) ? (!plus) ? plus = true : denominator -= denominator * 2 : (!plus) ? plus = false : plus = true;
		for (int i = (numerator < denominator) ? numerator : denominator; i > 1; i--)
		{
			if (numerator%i == 0 && denominator%i == 0)
			{
				numerator /= i;
				denominator /= i;
			}
		}
	}
};
#define CONSTRUCTORS_CHECK

Fraction operator*(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	Fraction result(0, buffL.get_numerator()*buffR.get_numerator(), buffL.get_denominator()*buffR.get_denominator());
	result.to_proper();
	result.yes();
	return result;
}
Fraction operator/(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	Fraction result(0, buffL.get_numerator()*buffR.get_denominator(), buffL.get_denominator()*buffR.get_numerator());
	result.to_proper();
	result.yes();
	return result;
}
Fraction operator+(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	Fraction result(0, buffL.get_numerator()*buffR.get_denominator() + buffR.get_numerator()*buffL.get_denominator(), buffL.get_denominator()*buffR.get_denominator());
	result.to_proper();
	result.yes();
	return result;
}
Fraction operator-(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	Fraction result(0, buffL.get_numerator()*buffR.get_denominator() - buffR.get_numerator()*buffL.get_denominator(), buffL.get_denominator()*buffR.get_denominator());
	result.to_proper();
	result.yes();
	return result;
}
bool operator>(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	return buffL.get_numerator()*buffR.get_denominator() > buffL.get_denominator()*buffR.get_numerator();
}
bool operator<(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	return buffL.get_numerator()*buffR.get_denominator() < buffL.get_denominator()*buffR.get_numerator();
}
bool operator==(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	return buffL.get_numerator()*buffR.get_denominator() == buffL.get_denominator()*buffR.get_numerator();
}
bool operator>=(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	return buffL.get_numerator()*buffR.get_denominator() >= buffL.get_denominator()*buffR.get_numerator();
}
bool operator<=(Fraction buffL, Fraction buffR)
{
	buffL.to_improper();
	buffR.to_improper();
	return buffL.get_numerator()*buffR.get_denominator() <= buffL.get_denominator()*buffR.get_numerator();
}
std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
	if (obj.get_intager())
	{
		os << obj.get_intager();
	}
	if (obj.get_numerator())
	{
		if (obj.get_intager())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_intager())os << ")";
	}
	if (obj.get_intager() == 0 && obj.get_numerator() == 0)os << 0;
	return os;
}



void main()
{
	setlocale(LC_ALL, "");
	//Fraction A;
	//try
	//{
	//	A.set_intager(2);
	//	A.set_numerator(3);
	//	A.set_denominator(0);
	//}
	//catch (std::exception e)
	//{
	//	std::cerr << e.what() << std::endl;
	//}
#ifdef CONSTRUCTORS_CHECK

#endif // CONSTRUCTORS_CHECK
#ifdef FRACTION_CHECKS


	Fraction A;
	A.print();

	Fraction B = 3;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.to_improper();
	D.print();

	Fraction E(2, 11);
	E.to_proper();
	E.print();

	Fraction F(5, 5);
	F.to_improper();
	F.print();

	E += F;

	E.print();


	//Fraction A(1, 2);
	////++A;

	//Fraction B = A++;
	//A.print();
	//B.print();
	///*int i = 0;
	//int j = i++;
	//std::cout << i << std::endl;
	//std::cout << i << std::endl;*/

	//std::cout << A<<std::endl;

	Fraction A(1, 2), B(3, 4);
	std::cout << (A == B) << std::endl;
#endif // FRACTION_CHECKS


#ifdef TYPE_CONVERTION
	//std::cout << (char)43 << std::endl;//C-like notation
	//std::cout<<char(44)<<std::endl;//Functional notation
	//std::cout<<5.8 + 2 * '+'<<std::endl;
	//std::cout << typeid('a' - 'A').name() << std::endl;
	//std::cout << (double)7 / 2 << std::endl;


	Fraction B;
	B = (Fraction)8;
	Fraction C(5, 3, 8);
	double c = (double)C;
	std::cout << c << std::endl<<C<<std::endl;
	Fraction D;
	//(double) D=5;
	//std::cout << D << std::endl;
#endif // TYPE_CONVERTION
}