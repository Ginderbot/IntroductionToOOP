#include <iostream>
#include <string>


template<typename T>
class List
{
	class Element
	{
		T data;
		Element*pNext;
		Element*pPrev;
	public:
		Element(T data, Element*pNext = nullptr, Element*pPrev = nullptr);
		~Element();
		friend class List;
	};
	Element*head;//�������� ��������� �� ������ ������
	Element*tail;//�������� ��������� �� ����� ������
	unsigned int size;//���������� ��������� ������
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp);
		~Iterator();
		//Operators:
		Iterator& operator++() 
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		const T& operator*()const
		{
			return Temp->data;
		}
		T& operator*()
		{
			return Temp->data;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
	};
	class ReverseIterator
	{
		Element *Temp;
	public:
		ReverseIterator(Element*Temp)
		{
			this->Temp = Temp;
		}
		~ReverseIterator()
		{

		}
		// Operators
		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}

		const T& operator*()const
		{
			return Temp->data;
		}
		T& operator*()
		{
			return Temp->data;
		}
		bool operator ==(const ReverseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator !=(const ReverseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
	};

	Iterator begin();
	Iterator end()
	{
		return nullptr;
	}
	const ReverseIterator rbegin()const
	{
		return tail;
	}
	const ReverseIterator rend()const
	{
		return nullptr;
	}
	const Iterator begin()const
	{
		return this->head;
	}
	const Iterator end()const
	{
		return nullptr;
	}
	ReverseIterator rbegin()
	{
		return tail;
	}
	ReverseIterator rend()
	{
		return nullptr;
	}
	List()
	{
		head = tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	List(const std::initializer_list<T>& il) :List()
	{
		std::cout << typeid(il.begin()).name() << std::endl;
		/*for (int const*it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}*/
		for (T i : il)
		{
			push_back(i);
		}
	}
	List(const List<T>&other) :List()
	{
		/*	for (Element*Temp = other.head; Temp; Temp = Temp->pNext)push_back(Temp->data);*/
		for (Iterator it = other.head; it != nullptr; it++)push_back(*it);
		std::cout << "LCopyConstructor" << std::endl;
	}
	List(List<T>&&other)
	{
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = other.tail = nullptr;
		std::cout << "LMoveConstructor" << std::endl;
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
	//operators
	List<T>& operator = (const List<T>& other)
	{
		if (this == &other)return *this;
		while (head)pop_front();
		for (Element* Temp = other.head; Temp; Temp = Temp->pNext)push_back(Temp->data);
		std::cout << "LCopyAssignment" << this << std::endl;
		return *this;
	}
	List<T>& operator = (List<T>& other)
	{
		while (head)pop_front();
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = other.tail = nullptr;
		std::cout << "LMoveConstructor" << this << std::endl;
		return *this;
	}
	//adding elements
	void push_front(T data)
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
	void push_back(T data)
	{
		if (head == nullptr)
		{
			head = tail = new Element(data);
			size++;
			return;
		}
		tail = tail->pNext = new Element(data, nullptr, tail);
		size++;
	}
	void insert(int index, T data)
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
			for (int i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
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
		Temp->pPrev = Temp->pPrev->pNext = new Element(data, Temp, Temp->pPrev);
		size++;
	}
	//remuving elemtnts
	void pop_front()
	{
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			if (size)size--;
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
		if (index >= size)throw std::exception("Error: Out of range");
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index == size - 1)
		{
			pop_back();
			return;
		}
		Element* Temp;
		if (index < size / 2)
		{
			Temp = head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (int i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		size--;
	}
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
template<typename T>
List<T>::Iterator List<T>::begin()
{
	return this->head;
}
//class List::Element
template<typename T>
List<T>::Element::Element(T data, Element* pNext, Element* pPrev) :data(data), pNext(pNext), pPrev(pPrev)
{
	std::cout << "EConstructor:\t" << this << std::endl;
}
template<typename T>
List<T>::Element::~Element()
{
	std::cout << "EDestructor:\t" << this << std::endl;
}
//class List::Iterator
template<typename T>
List<T>::Iterator::Iterator(Element* Temp)
{
	this->Temp = Temp;
	//std::cout << "ItConstructor\t" <<this<< std::endl;
}
template<typename T>
List<T>::Iterator::~Iterator()
{
	//std::cout << "ItDestructor\t" <<this<< std::endl;
}

//class List::ReverseIterator



template<typename T>
List<T> operator+(const List<T>& left, const List<T>&right)
{
	List<T> buffer = left;
	for (List<T>::Iterator it = right.begin(); it != right.end(); it++)
	{
		buffer.push_back(*it);
	}
	std::cout << "Global operator+\n";
	return buffer;
}
//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK
//#define OPERATORS+CHECK


void main()
{
#ifdef OPERATORS+CHECK
	int n;
	std::cout << "Input list size: "; //std::cin >> n;
#ifdef BASE_CHECK
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
	try
	{
		std::cout << "Input index: "; std::cin >> index;
		//	std::cout << "Intex value: "; std::cin >> data;
		list.erase(index);
		list.print();
		list.print_revers();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
#endif // BASE_CHECK
#ifdef CONSTRUCTORS_CHECK

	List list = { 3,5,8,13,21 };
	list = list;
	list.print();
	list.print_revers();

	List list2 = list;
	//list2= list;
	list2.print();
	list2.print_revers();
#endif // CONSTRUCTORS_CHECK


	int arr[] = { 3,5,8,13,21 };
	for (int i : arr) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;


	List list = { 3,5,8,13,21 };
	List list2 = { 34,55,89 };
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "___________________________________________\n";

	for (int i : list + list2)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	List list3;
	list3 = list + list2;
	list3.print();
	std::cout << "___________________________________________\n";

	for (List::ReverseIterator rit = list3.rbegin(); rit != list3.rend(); rit++)
	{
		std::cout << *rit << "\t";
	}
	std::cout << std::endl;
	std::cout << "___________________________________________\n";
#endif // OPERATORS+CHECK
	/*List<int> list1 = { 3,5,8,13,21 };
	for (List<int>::Iterator it = list1.begin(); it != list1.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	List<int> list2 = { 34,55,89 };
	for (int i:list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<int> list3 = list1 + list2;
	list3.print();
	for (int i : list3)
		std::cout << i << "\t";
	std::cout << std::endl;*/

	/*List<double> list1 = { 3.1,5.1,8.1,13.1,21.1 };
	for (double i : list1)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<double> list2 = { 34.1,55.1,89.1 };
	for (double i : list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<double> list3 = list1 + list2;
	list3.print();
	for (double i : list3)
		std::cout << i << "\t";
	std::cout << std::endl;
*/

	List<std::string> list1 = { "Number","one" };
	for (std::string i : list1)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<std::string> list2 = { "Number","two" };
	for (std::string i : list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<std::string> list3 = list1 + list2;
	list3.print();
	for (std::string i : list3)
		std::cout << i << "\t";
	std::cout << std::endl;



	//List<double> list2 = { 2.7,3.14,5.5};
	//for(double i:list2)
	//	std::cout<<i<<"\t";
	//std::cout << std::endl;

	//List<std::string> list3 = { "Hello","World!","How","are","you?" };
	//for (std::string i : list3)
	//{
	//	std::cout << i << "\t";
	//}
	//std::cout << std::endl;
}