#include <iostream>
#include "Header.h"


//class List
template<typename T>
typename List<T>::Iterator List<T>::begin()
{
	return this->head;
}
template<typename T>
typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>
const typename List<T>::ReverseIterator List<T>::rbegin()const
{
	return tail;
}
template<typename T>
const typename List<T>::ReverseIterator List<T>::rend()const
{
	return nullptr;
}
template<typename T>
const typename List<T>::Iterator List<T>::begin()const
{
	return this->head;
}
template<typename T>
const typename List<T>::Iterator List<T>::end()const
{
	return nullptr;
}
template<typename T>
typename List<T>::ReverseIterator List<T>::rbegin()
{
	return tail;
}
template<typename T>
typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
template<typename T>
List<T>::List()
{
	head = tail = nullptr;
	size = 0;
	std::cout << "LConstructor:\t" << this << std::endl;
}
template<typename T>
List<T>::List(const std::initializer_list<T>& il) :List()
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
template<typename T>
List<T>::List(const List<T>&other) :List()
{
	/*	for (Element*Temp = other.head; Temp; Temp = Temp->pNext)push_back(Temp->data);*/
	for (Iterator it = other.head; it != nullptr; it++)push_back(*it);
	std::cout << "LCopyConstructor" << std::endl;
}
template<typename T>
List<T>::List(List<T>&&other)
{
	this->head = other.head;
	this->tail = other.tail;
	this->size = other.size;
	other.head = other.tail = nullptr;
	std::cout << "LMoveConstructor" << std::endl;
}
template<typename T>
List<T>::~List()
{
	while (tail || head)
	{
		pop_front();
		pop_back();
	}
	std::cout << "LDestructor:\t" << this << std::endl;
}
//operators
template<typename T>
List<T>& List<T>::operator = (const List<T>& other)
{
	if (this == &other)return *this;
	while (head)pop_front();
	for (Element* Temp = other.head; Temp; Temp = Temp->pNext)push_back(Temp->data);
	std::cout << "LCopyAssignment" << this << std::endl;
	return *this;
}
template<typename T>
List<T>& List<T>::operator = (List<T>& other)
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
template<typename T>
void List<T>::push_front(T data)
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
template<typename T>
void List<T>::push_back(T data)
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
template<typename T>
void List<T>::insert(int index, T data)
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
template<typename T>
void List<T>::pop_front()
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
template<typename T>
void List<T>::pop_back()
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
template<typename T>
void List<T>::erase(int index)
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
template<typename T>
void List<T>::print()const
{
	for (Element*Temp = head; Temp != nullptr; Temp = Temp->pNext)
	{
		std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
	}
	std::cout << "List size:\t" << size << std::endl;
}
template<typename T>
void List<T>::print_revers()const
{
	for (Element*Temp = tail; Temp != nullptr; Temp = Temp->pPrev)
	{
		std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
	}
	std::cout << "List size:\t" << size << std::endl;
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
//operators:
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
template<typename T>
const T& List<T>::Iterator::operator*()const
{
	return Temp->data;
}
template<typename T>
T& List<T>::Iterator::operator*()
{
	return Temp->data;
}
template<typename T>
bool List<T>::Iterator::operator==(const Iterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>
bool List<T>::Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}
//class List::ReverseIterator
template<typename T>
List<T>::ReverseIterator::ReverseIterator(Element*Temp)
{
	this->Temp = Temp;
}
template<typename T>
List<T>::ReverseIterator::~ReverseIterator()
{

}
// Operators
template<typename T>
typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator++()
{
	Temp = Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::ReverseIterator List<T>::ReverseIterator::operator++(int)
{
	ReverseIterator old = *this;
	Temp = Temp->pPrev;
	return old;
}
template<typename T>
const T& List<T>::ReverseIterator::operator*()const
{
	return Temp->data;
}
template<typename T>
T& List<T>::ReverseIterator::operator*()
{
	return Temp->data;
}
template<typename T>
bool List<T>::ReverseIterator::operator ==(const ReverseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>
bool List<T>::ReverseIterator::operator !=(const ReverseIterator& other)const
{
	return this->Temp != other.Temp;
}
