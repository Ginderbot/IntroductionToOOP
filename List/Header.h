#pragma once
class List
{
	class Element
	{
		int data;
		Element*pNext;
		Element*pPrev;
	public:
		Element(int data, Element*pNext = nullptr, Element*pPrev = nullptr);
		~Element();
		friend class List;
	};
	Element*head;//Содержет указатель на начало списка
	Element*tail;//Содержет указатель на конец списка
	unsigned int size;//количество элементов списка
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp);
		~Iterator();
		//Operators:
		Iterator& operator++();
		Iterator operator++(int);
		const int& operator*()const;
		int& operator*();
		bool operator==(const Iterator& other)const;
		bool operator!=(const Iterator& other)const;
	};
	class ReverseIterator
	{
		Element *Temp;
	public:
		ReverseIterator(Element*Temp);
		~ReverseIterator();
		// Operators
		ReverseIterator& operator++();
		ReverseIterator operator++(int);
		const int& operator*()const;
		int& operator*();
		bool operator ==(const ReverseIterator& other)const;
		bool operator !=(const ReverseIterator& other)const;
	};

	Iterator begin();
	Iterator end();
	const ReverseIterator rbegin()const;
	const ReverseIterator rend()const;
	const Iterator begin()const;
	const Iterator end()const;
	ReverseIterator rbegin();
	ReverseIterator rend();
	List();
	List(const std::initializer_list<int>& il);
	List(const List&other);
	List(List&&other);
	~List();
	//operators
	List& operator = (const List& other);
	List& operator = (List& other);
	//adding elements
	void push_front(int data);
	void push_back(int data);
	void insert(int index, int data);
	//delete elements
	void pop_front();
	void pop_back();
	void erase(int index);
	//remuving elemtnts

	//metods
	void print()const;
	void print_revers()const;
};