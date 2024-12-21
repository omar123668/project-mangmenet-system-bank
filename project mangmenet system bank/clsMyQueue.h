#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;
template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList<T>_MyList;
public:

	void push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}
	void pop()
	{
		_MyList.DeleteFirstNode();
	}
	T front()
	{
		return _MyList.GetItem(0);
	}
	T back()
	{
		return _MyList.GetItem(Size()- 1);
	}
	T Size()
	{
		return _MyList.Size();
	}
	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}
	T GetItem(T Index)
	{
		return _MyList.GetItem(Index);
	}
	bool UpdateItem(T Index, T NewValue)
	{
		return _MyList.UpdateItem(Index, NewValue);
	}
	void Reverse()
	{
		_MyList.Reverse();
	}
	void InsertAfter(int Index, T NewValue)
	{
		_MyList.InsertAfter(Index, NewValue);
	}
	void InsertAtFront(T NewValue)
	{
		_MyList.InsertAtBeginning(NewValue);
	}
	void InsertAtBack(T NewValue)
	{
		_MyList.InsertAtEnd(NewValue);
	}
	void Clear()
	{
		_MyList.Clear();
	}
	void Print()
	{
		_MyList.PrintList();
	}
};

