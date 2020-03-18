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
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~List()
	{
		std::cout << "LDestructor:\t" << this << std::endl;
	}
	//adding elements
	void push_front(int data)
	{
		if(head==nullptr)
		{
			head = tail = new Element(data);
			return;
		}
		head =head->pPrev= new Element(data, head);
		size++;
	}
	//remuving elemtnts

	//metods
	void print()const
	{
		for (Element*Temp = head; Temp != nullptr; Temp = Temp->pNext)
		{
			std::cout << Temp->pPrev << "\t" <<Temp<<"\t"<< Temp->data<< "\t" << Temp->pNext<<std::endl;
		}
		std::cout << "List size:\t" << size<<std::endl;
	}
	void print_revers()const
	{
		for (Element*Temp=tail;Temp!=nullptr;Temp=Temp->pPrev)
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
		list.push_front(rand() % 100);
	}
	list.print();
	list.print_revers();
}