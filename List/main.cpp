#include <iostream>

class List
{
	class Element
	{
		int data;
		Element*pNext;
		Element*pPrev;
	public:
		Element(int data, Element*pNext = nullptr, Element*pPrev = nullptr) :data(data), pNext(pNext), pPrev(pPrev)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class List;
	};
	Element*head;//Содержет указатель на начало списка
	Element*tail;//Содержет указатель на конец списка
	unsigned int size;//количество элементов списка
public:
	List()
	{
		head = tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~List()
	{
		while (tail || head)
		{
			pop_front();
			pop_back();
		}
		std::cout << "LDestructor:\t" << this << std::endl;
	}
	//adding elements
	void push_front(int data)
	{
		if (head == nullptr)
		{
			head = tail = new Element(data);
			size++;
			return;
		}
		head = head->pPrev = new Element(data, head);
		size++;
	}
	void push_back(int data)
	{
		if (head == nullptr)
		{
			head = tail = new Element(data);
			size++;
			return;
		}
		tail = tail->pNext = new Element(data,nullptr,tail);
		size++;
	}
	void insert(int index, int data) 
	{
		Element* Temp;
		if (index > size)throw std::exception("Error");
		else if (index == 0)
		{
			push_front(data);
				return;
		}
		else if (index == size)
		{
			push_back(data);
			size++;
			return;
		}
		else if (index <= size / 2)
		{
			Temp = head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else if (index > size / 2)
		{
			Temp = tail;
			for (int i = 0; i < size-1-index; i++)Temp = Temp->pPrev;
		}
		else
		{
			std::cout << "Error" << std::endl;
			return;
		}
		/*Element* New = new Element(data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/
		Temp =Temp->pNext=Temp->pNext->pPrev=new Element(data,head,Temp->pNext->pNext) ;
		size++;
	}
	//delete elements
	void pop_front()
	{
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			if(size)size--;
			return;
		}
		head = head->pNext;
		delete head->pPrev;
		head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (head == tail)
		{
			delete tail;
			head = tail = nullptr;
			if (size)size--;
			return;
		};
		tail = tail->pPrev;
		delete tail->pNext;
		tail->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{

	}
	//remuving elemtnts

	//metods
	void print()const
	{
		for (Element*Temp = head; Temp != nullptr; Temp = Temp->pNext)
		{
			std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
		}
		std::cout << "List size:\t" << size << std::endl;
	}
	void print_revers()const
	{
		for (Element*Temp = tail; Temp != nullptr; Temp = Temp->pPrev)
		{
			std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
		}
		std::cout << "List size:\t" << size << std::endl;
	}
};
//class List 
//{
//	Element *Head;//Адрес следуйщего элемента
//	Element *Tail;//Адрес предыдущего элемента
//	unsigned int Size;//Размер элемента
//public:
//	const Element* get_head()const
//	{
//		return Head;
//	}
//	Element* get_head()
//	{
//		return Head;
//	}
//	unsigned int get_size()const
//	{
//		return Size;
//	}
//	const Element* get_tail()const
//	{
//		return Tail;
//	}
//	Element* get_tail()
//	{
//		return Tail;
//	}
//};


void main()
{
	int n;
	std::cout << "Input list size: "; std::cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.print_revers();
	//std::cout << "____________________________add front___________________________________" << std::endl;
	//list.push_front(100);
	//list.print();
	//list.print_revers();
	//std::cout << "____________________________add back____________________________________" << std::endl;
	//list.push_back(200);
	//list.print();
	//list.print_revers();
	//std::cout << "__________________________delete front__________________________________" << std::endl;
	//list.pop_front();
	//list.print();
	//list.print_revers();
	//std::cout << "__________________________delete back___________________________________" << std::endl;
	//list.pop_back();
	//list.print();
	//list.print_revers();
	std::cout << "______________________________insert____________________________________" << std::endl;
	int index;
	int data;
	std::cout << "Введите индекс: "; std::cin >> index;
	std::cout << "Введите значение: "; std::cin >> data;
	list.insert(index,data);
	list.print();
	list.print_revers();
}