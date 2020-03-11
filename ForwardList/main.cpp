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
	unsigned int get_size()const
	{
		return Size;
	}
	ForwardList()
	{
		Head = nullptr; // Если список пуст то его голова указывает на 0
		Size = 0;
		std::cout << "LConstructor" << "\t" << "\t" << this << std::endl;
	}
	ForwardList(int size):ForwardList()
	{
		while (size--)push_front(0);
	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	~ForwardList()
	{
		while (Head)pop_front();
		std::cout << "LDestructor" << "\t" << "\t" << this << std::endl;
	}

	//Operators:
	int& operator [](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp=Temp->pNext;
		return Temp->Data;
	}

	//Добавление елемента
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		Head = new Element(Data, Head);
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
		/*Element*New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp = new Element(Data, Temp->pNext);
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

	void erase(int index,int Data)
	{
		if (index>=this->Size)
		{
			throw std::exception("Error: Out of range when erasing.");
		}
		if (index==0)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)Temp = Temp->pNext;
		Element* buff = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete buff;
		Size--;
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
		std::cout <<"List size: "<< Size <<" elements"<< std::endl;

	}
};

//#define BASE_FUNCTIONS_CHECK
//#define CONSTRUCTORS_CHECK_1
#define CONSTRUCTORS_CHECK_2
void main()
{
	int n;
	std::cout << "Input list size: "; std::cin >> n;
#ifdef BASE_FUNCTIONS_CHECK



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
	//int value;
	//std::cout << "Input index"; std::cin >> index;
	//std::cout << "Input value"; std::cin >> value;

	//std::cout << delimiter;
	//fl.insert(index,value);
	//fl.print();
	//std::cout << delimiter;
	//

	//ForwardList fl2;
	//fl2.push_back(3);
	//fl2.push_back(5);
	//fl2.push_back(8);
	//fl2.push_back(13);
	//fl2.push_back(21);
	//fl2.print();

	//try
	//{
	//	std::cout << "Input index: "; std::cin >> index;
	//	fl.erase(index);
	//	fl.print();
	//}
	//catch (const std::exception& e)
	//{
	//	std::cerr << e.what() << std::endl;
	//	/*cin - Console Input;
	//	cout - Console Output;
	//	ceer -*/
	//}
#endif // BASE_FUNCTIONS_CHECK
#ifdef CONSTRUCTORS_CHECK_1
	ForwardList fl(n);
	for (int i = 0; i < fl.get_size(); i++)
	{
		fl[i] = rand() % 100;
	}
	for (int i = 0; i < fl.get_size(); i++)
	{
		std::cout << fl[i] << "\t";
	}
	std::cout << std::endl;
#endif // CONSTRUCTORS_CHECK_!
#ifdef CONSTRUCTORS_CHECK_2
	ForwardList list = { 3,5,8,13,21 };
	for (int i = 0; i < list.get_size(); i++)
	{
		std::cout << list[i] << "\t";
	}
	std::cout << std::endl;

#endif // CONSTRUCTORS_CHECK_2

}