#include<iostream>
//#define CONSTRUCTORS
class Point
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
		if (abs(x) <= 100) //abs() - модуль числа.
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
		//if - отфильтровывает некорректные значени€.
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors:
	/*Point()
	{
	x = y = 0;
	std::cout << "Default constructor:\t" << this << std::endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		std::cout << "Constructor:\t" << this << std::endl;
	}
	~Point()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}

	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignment:" << this << std::endl;

	}

	// Methods:
	void print() const
	{
		std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
	}
};

//#define BASICS
//#define ENCAPSULATION

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	int a; //ќбъ€вление переменной 'a', типа 'int'.
	Point A; //ќбъ€вление переменной 'A', типа 'Point'.
	//—оздание (объ€вление) объекта 'A', типа 'Point'.
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A; //ќбъ€влений указател€ на 'Point'  'pA'...
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;
#endif // BASICS
#ifdef ENCAPSULATION
	Point A;
	A.set_x(5);
	A.set_y(3);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif // ENCAPSULATION
#ifdef Constructors
	const Point B;
	/*std::cout << A.get_x() << std::endl;*/
	B.print();

	Point C = 5;
	C.print();

	Point D = 6;
	D.print();

	Point E(5, 2);
	E.print();

	//Copy constructor
	Point F = E;
	F.print();
	Point G;
	G = E;

#endif // Constructors

	Point A(5, 2);
	A.print(); // Default constructor
	Point B; //Copy assignment
	B = A;
	B.print();
}