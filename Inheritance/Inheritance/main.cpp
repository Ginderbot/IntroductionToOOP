#include <iostream>

class Box
{
	double width;
	double length;
	double height;
	bool closed;
public:
	Box(double width, double length, double height) :width(width), length(length), height(height), closed(true)
	{
		std::cout << "BoxConstructor:\t" << this << std::endl;
	}
	~Box()
	{
		std::cout << "BoxDestructor:\t" << this << std::endl;
	}

	void open()
	{
		closed = false;
	}
	void close()
	{
		closed = true;
	}
	void get_status()const
	{
		std::cout << "Box is " << (closed ? "closed" : "opened") << std::endl;
	}
};

class GiftBox :public Box
{
	std::string cover_color;
	bool bant;
public:
	GiftBox(double width,double length, double height, std::string color) :Box(width,length,height)
	{
		std::cout << "GBConstructor:\t" << this << std::endl;
	}
	~GiftBox()
	{
		std::cout << "GBDestructor:\t" << this << std::endl;
	}
};

void main()
{
	/*Box box1(2, 2, 1);
	box1.open();
	box1.close();
	box1.get_status();*/
	GiftBox box2(2,2,1,"green");
	box2.get_status();
}