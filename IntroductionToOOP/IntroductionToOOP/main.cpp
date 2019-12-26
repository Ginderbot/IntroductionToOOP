#include<iostream>
//#define CONSTRUCTORS
//#define DISTANCE
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
		(abs(x) <= 100) ? this->x = x : this->x = 0;//abs() - модуль числа.
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

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	//Point operator+(const Point&other)
	//{
	//	Point result;
	//	result.x = this->x + other.x;
	//	result.y = this->y + other.y;
	//	return result;
	//}

	// Methods:
	void print() const
	{
		std::cout << "x = " << x << "\t" << "y = " << y << std::endl;
	}

	double distance(const Point& other) const
	{
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}

};

//double distance(Point A, Point B)
//{
//	double x_distance = A.get_x() - B.get_x();
//	double y_distance = A.get_y() - B.get_y();
//	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
//	return distance;
//}

//#define BASICS
//#define ENCAPSULATION

double distance(const Point& A, const Point& B)
{
	return sqrt(pow(B.get_x() - A.get_x(), 2) + pow(B.get_y() - A.get_y(), 2));
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	//result.set_x(left.get_x() + right.get_x());
	//result.set_y(left.get_y() + right.get_y());
	std::cout << "Global operator+" << std::endl;
	//return result;
	return Point(left.get_x() + right.get_x(), left.get_y() + right.get_y());
}
Point operator-(const Point& left, const Point& right)
{
	Point result;
	std::cout << "Global operator-" << std::endl;
	return Point(left.get_x() - right.get_x(), left.get_y() - right.get_y());
}
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

#ifdef DISTANCE
	Point A(5, 2);
	A.print(); // Default constructor
	Point B; //Copy assignment
	B = A;
	B.print();

	/*Point A(2, 5);
	Point B(3, 7);
	A.print();
	B.print();
	std::cout << A.distance(B) << std::endl;
	std::cout << distance(A, B) << std::endl;*/
	std::cout << "–ассто€ние между точками: " << distance(A, B) << std::endl;
#endif // DISTANCE

	//Point A, B, C;
	//A = B = C = Point(5, 3);

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(5, 2);
	Point B(8, 3);
	Point C;
	C= A + B;
	//C = A + B;
	//A.operator+(B).operator+(C).operator+(A).print();
	//A += B;
	C.print();

	A.print();
	B.print();
}