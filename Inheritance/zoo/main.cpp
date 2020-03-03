#include<iostream>

class Animal
{
public:
	virtual ~Animal()
	{

	}
	virtual void sound() const = 0;
	/*{
		std::cout << "Some sound" << std::endl;
	}*/
};

class Cat :public Animal
{
public:
	virtual void sound() const
	{
		std::cout << "ּÿף" << std::endl;
	}
};

class Dog :public Animal
{
public:
	virtual void sound() const
	{
		std::cout << "ֳאג" << std::endl;
	}
};

class ShepherdDog :public Dog
{

};

class Bulldog :public Dog
{

};

class ChihuaHua :public Dog
{
	void sound() const
	{
		std::cout << "ׂÿפ עÿפ קאפ 3.14" << std::endl;
	}
};

class Mouse :public Animal
{
public:
	void sound() const
	{
		std::cout << 3.14 << std::endl;
	}
};

class Wild_Animal :public Animal
{

};

class Woolf :public Wild_Animal
{
public:
	void sound() const
	{
		std::cout << "Auuuuu" << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Cat tom;
	Dog spike;
	Mouse jerry;

	Animal* p_tom = &tom;
	Animal* p_jerry = &jerry;
	Animal* p_spike = &spike;*/

	Animal*zoo[] =
	{
		new Cat(),
		new Dog(),
		new Mouse(),
		new ShepherdDog(),
		new Bulldog(),
		new ChihuaHua()
	};

	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}

	//Animal animal;
	//Wild_Animal animal;
	Woolf wolf;
	wolf.sound();
}