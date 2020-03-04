#include <iostream>

class Element
{
	int Data;
	Element*pNext;
public:
	Element(int Data, Element*pNext = nullptr) :Data(Data), pNext(pNext)
	{
		std::cout << "EConstructor" << this << std::endl;
	}
	~Element()
	{
		std::cout << "EDestructor" << this << std::endl;
	}
	friend class ForwardList;
};
class ForwardList
{
	Element*Head;
public:
	ForwardList()
	{
		Head = nullptr; // Если список пуст то его голова указывает на 0
		std::cout << "LConstructor" << this << std::endl;
	}
	~ForwardList()
	{
		std::cout << "LDestructor" << this << std::endl;
	}

	//Добавление елемента
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}

	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element*Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
	}
	//metods
	void print() const
	{
		Element*Temp = Head;// Итератор это указатель при помощи которого можно получить доступ к елементам структуры данных

		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;
		}
	}
};

void main()
{
	int n;
	std::cout << "Input list size"; std::cin >> n;
	//Element e(5);
	ForwardList fl;

	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}
	fl.push_back(1024);
	fl.print();
}