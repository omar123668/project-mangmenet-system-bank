#pragma once
#include"clsDyanmicArray.h"
#include"clsDyanmicArray.h"
using namespace std;
template<class T>
class clsMyQueueArr
{
protected:
	clsDyanmicArray<T>_MyList;
public:

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}
	void pop()
	{
		_MyList.DeleteFirstItem();
	}
	T front()
	{
		return _MyList.GetItem(0);
	}
	T back()
	{
		return _MyList.GetItem(Size()-1);
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
		return _MyList.SetItem(Index, NewValue);
	}
	void Reverse()
	{
		_MyList.Reverse();
	}
	void InsertAfter(int Index, T NewValue)
	{
		_MyList.Insertafter(Index, NewValue);
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

