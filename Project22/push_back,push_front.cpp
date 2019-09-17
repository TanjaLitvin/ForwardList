#include<iostream>
using namespace std;

class Element
{
	int Data;      //значение элемента
	Element* pNext;  //адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		cout << "EConstructor:\t" << this << endl;
	}

	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class List;
};
class List
{
	Element* Head; //адрес начала списка
public:
	List()
	{
		this->Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	void push_front(int Data)
	{
		//1)создаем новый элемент:
		Element* New = new Element(Data);
		//2)"привязываем новый элемент к голове(Head)":
		New->pNext = Head;
		//3)голову переводим на новый элемент:
		Head = New;


	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
	}
	void pop_front()
	{
		Element* Temp = Head;
		Head = Head->pNext;
		delete Temp;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}
	void print()
	{
		//1)создаем итератор
		Element* Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
};
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Vvedite razmer spiska:\t"; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.push_front(555);
	list.print();
	list.pop_front();
	list.print();
	list.push_back(555);
	list.print();
	list.pop_back();
	list.print();
}
