#include<iostream>

class point
	//stract
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		(/*x>=-100&&x<=100*/abs(x) <= 100) ? this->x = x : this->x == 0; // фильтраци€ некоректных значений
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define BASICS
#define ENCAPSULATION


void main()
{
	setlocale(LC_ALL, "");

#ifdef BACICS


	int a;
	point A;
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	point* pA = &A;// объ€вление указател€ на 'point' 'pA'
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;
#endif // BACICS

#ifdef ENCAPSULATION
	point A;
	A.set_x(5);
	A.set_y(3);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif // ENCAPSULATION

}