#pragma once
using namespace std;
template <class T>
class clsDyanmicArray
{
protected:
	T _Size;
	T* _TempArray;
public:
	T* OriginalArray;

	clsDyanmicArray(T _Size=0)
	{
		if (_Size < 0)
			_Size = 0;
		
		 this->_Size = _Size;
		 OriginalArray= new T[_Size];
	}
	~clsDyanmicArray()
	{
		delete[]  OriginalArray;
	}
	bool SetItem(int Index, T Value)
	{
		if (Index > _Size || _Size < 0)
		{
			return false;
		}
		else
		OriginalArray[Index] = Value;
		return true;
	}
	T Size()
	{
		return _Size;
	}
	bool IsEmpty()
	{
		return _Size == 0 ? true : false;
	}
	void Resize(T NewSize)
	{
		if (NewSize < 0)
		{
			NewSize = 0;
		}

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (short i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	T GetItem(T Index)
	{
		return OriginalArray[Index];
	}
	void Reverse()
	{
		_TempArray = new T[_Size];
		int counter = 0;
		for (short i = _Size-1;i>=0; i--)
		{
			_TempArray[counter] = OriginalArray[i];
				counter++;
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	void Clear()
	{ 
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}
	bool DeleteItemAt(T Index)
	{
		if (Index >= _Size || Index < 0)
		{
			return false;
		}
		_Size--;
		_TempArray =new T[_Size];
		for (short I = 0; I < Index; I++)
		{
			_TempArray[I] = OriginalArray[I];
		}

		for (short i = Index+1; i < _Size+1; i++)
		{
			_TempArray[i-1] = OriginalArray[i]; 
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}
	void DeleteLastItem()
	{
		DeleteItemAt(_Size--);
	}
	int Find(T Value)
	{
		for (short i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] ==Value)
				return i;
		}
		return -1;
	}
	bool DeleteItem(T Value)
	{
		int Index = Find();
		if (Index == -1)
			return false;
		
		DeleteItemAt(Index);
		return true;
	}
	bool InsertAt(T Index, int Value)
	{
		if (Index > _Size || Index < 0)
			return false;

		_Size++;
		_TempArray = new T[_Size];

		for (short i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_TempArray[Index] = Value;

		for (short i = Index; i < _Size-1; i++)
		{
			_TempArray[i+1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}
	bool InsertBefore(T Index, int Value)
	{
		if(Index<1)
		return InsertAt(0, Value);
		else
		return InsertAt(Index - 1, Value);
	}
	bool Insertafter(T Index, int Value)
	{
		if(Index>=_Size)
			return InsertAt(_Size-1, Value);
		else
		InsertAt(Index+1, Value);
	}
	bool InsertAtEnd(int Value)
	{
		return InsertAt(_Size, Value);
	}
	void PrintList()
	{
		for (int I = 0; I <= _Size - 1; I++)
		{
			cout << OriginalArray[I] << " ";
		}
		cout << "\n";
	}
};

