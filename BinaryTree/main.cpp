#include <iostream>

class BTree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			std::cout << "EConstructor\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor\t" << this << std::endl;
		}
		friend class BTree;
	}*Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}
	BTree() :Root(nullptr)
	{
		std::cout << "TConstructor\t" << this << std::endl;
	}
	~BTree()
	{
		clear(this->Root);
		std::cout << "TDestructor\t" << this << std::endl;
	}
	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}
	void print()
	{
		print(this->Root);
		std::cout << std::endl;
	}
	int minValue()
	{
		return minValue(this->Root);
	}

	int maxValue()
	{
		return maxValue(this->Root);
	}


	//add Elements
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)//Если дерево пустое тодобавляем едемент прямо в корень
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
	int minValue(Element* Root)
	{
		return(Root->pLeft) ? minValue(Root->pLeft) : Root->Data;
		/*if (Root->pLeft == nullptr) return Root->Data;
			return minValue();*/
	}
	int maxValue(Element* Root)
	{
		return(Root->pRight) ? maxValue(Root->pRight) : Root->Data;
		//if (Root->pRight == nullptr)return Root->Data;
		//	return maxValue();
	}
	//Metods
	void print(Element*Root) const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		std::cout << Root->Data << "\t";
		print(Root->pRight);
	}
};

void main()
{
	int n;
	std::cout << "Input number elements: "; std::cin >> n;
	BTree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand()%100);
	}
	T800.print();
	std::cout<<"Min value: "<<T800.minValue()<<std::endl;
	std::cout<<"Max value: "<<T800.maxValue()<<std::endl;
}