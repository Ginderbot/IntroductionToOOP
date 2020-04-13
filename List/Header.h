#pragma once
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
		const T& operator*()const;
		T& operator*();
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

		const T& operator*()const;
		T& operator*();
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
	List(const std::initializer_list<T>& il);
	List(const List<T>&other);
	List(List<T>&&other);
	~List();
	//operators
	List<T>& operator = (const List<T>& other);
	List<T>& operator = (List<T>& other);
	//adding elements
	void push_front(T data);
	void push_back(T data);
	void insert(int index, T data);
	//remuving elemtnts
	void pop_front();
	void pop_back();
	void erase(int index);
	//metods
	void print()const;
	void print_revers()const;
};


