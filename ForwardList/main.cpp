#include <iostream>
#define delimiter "------------------------------------------\n"

class Element
{
	int Data;
	Element*pNext;
	static int count;
public:
	Element(int Data, Element*pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		std::cout << "EConstructor" << "\t" << "\t" << this << std::endl;
	}
	~Element()
	{
		count--;
		std::cout << "EDestructor" <<"\t" << "\t" << this << std::endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element*Head;
	unsigned int Size;
public:
	ForwardList()
	{
		Head = nullptr; // Если список пуст то его голова указывает на 0
		Size = 0;
		std::cout << "LConstructor" << "\t" << "\t" << this << std::endl;
	}
	~ForwardList()
	{
		std::cout << "LDestructor" << "\t" << "\t" << this << std::endl;
	}

	//Добавление елемента
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		Size++;
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
		Size++;
	}

	void insert(int index, int Data)
	{
		if (index > Size)
		{
			std::cout << "Error: Out of range" << std::endl;
			return;
		}
		Element* Temp = Head;
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element*New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		Size++;
	}

	//Удаление елементов
	void pop_front()
	{
		Element* buff = Head;//Запоминаем адрес удаляемого элемента
		Head = Head->pNext; //исключаем элемент из списка
		delete buff;
		Size--;
	}

	void pop_back()
	{
		Element*Temp = Head;
		while (Temp->pNext->pNext!=nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		Size--;
	}

	/*void erase(int index)
	{
		Element*Temp = Head;
		Element*buff = Head;
		int index;
		for (int i = 0; i < index; i++)
		{
			buff = buff->pNext;
		}
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
			if (Temp==buff)
			{
				delete buff->pNext;
				buff->pNext = nullptr;
				Temp = Temp->pNext;
			}
		}
	}*/

	//metods
	void print() const
	{
		Element*Temp = Head;// Итератор это указатель при помощи которого можно получить доступ к елементам структуры данных

		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;
		}
		std::cout <<"List size: "<< Size <<" elements"<< std::endl;

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
	/*fl.push_back(1024);*/
	fl.print();
	std::cout << delimiter;
	//fl.pop_front();
	//fl.print();
	//std::cout << delimiter;
	//fl.pop_back();
	//fl.print();

	int index;
	int value;
	std::cout << "Input index"; std::cin >> index;
	std::cout << "Input value"; std::cin >> value;

	std::cout << delimiter;
	fl.insert(index,value);
	fl.print();
	/*std::cout << delimiter;
	fl.erase();
	fl.print();*/

	ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.push_back(13);
	fl2.push_back(21);
	fl2.print();
}