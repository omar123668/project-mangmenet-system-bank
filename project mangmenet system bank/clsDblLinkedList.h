#pragma once
#include<iostream>
using namespace std;
template <class T>
class clsDblLinkedList
{
protected:
	int _Size = 0;

public:
	class Node
	{
	public:
		Node* Next;
		int Value;
		Node* Prv;
	};
	Node* Head = NULL;

	void InsertAtBeginning(T Value)
	{
		Node* newnode = new Node();

		newnode->Value = Value;
		newnode->Next = Head;
		newnode->Prv = NULL;

		if (Head != NULL)
		{
			Head->Prv = newnode;
		}
		Head = newnode;

		_Size++;
	}
	Node* Find(T Value)
	{
		Node* Current = Head;
		while (Current != NULL)
		{
			if (Current->Value == Value)
				return Current;
			Current = Current->Next;
		}
		return NULL;
	}
	void InsertAfter(Node* Current,T Value)
	{
		Node* newnode = new Node();

		newnode->Value = Value;
		newnode->Next = Current->Next;
		newnode->Prv = Current;

		if (Current->Next != NULL)
			Current->Next->Prv = newnode;

		Current->Next = newnode;
		_Size++;
	}
	void InsertAtEnd(T Value)
	{
		Node* newnode = new Node();

		newnode->Value = Value;
		newnode->Next = NULL;

		if (Head == NULL)
		{
			newnode->Prv = NULL;
			Head = newnode;
			_Size++;
		}
		else
		{
			Node* Current = Head;
			while (Current->Next != NULL)
			{
				Current = Current->Next;
			}
			Current->Next = newnode;
			newnode->Prv = Current;
			_Size++;
		}
	}
	void DeleteNode(Node*& NodeToDelete)
	{
		if (Head == NULL || NodeToDelete == NULL)
		{
			return;
		}

		if (NodeToDelete->Next != NULL)
		{
			NodeToDelete->Next->Prv = NodeToDelete->Prv;

		}
		if (NodeToDelete->Prv != NULL)
		{
			NodeToDelete->Prv->Next = NodeToDelete->Next;
		}
		free(NodeToDelete);
		_Size--;
	}
	void DeleteFirstNode()
	{
		if (Head == NULL)
		{
			return;
		}

		Node* Temp = Head;
		Head = Head->Next;

		if (Head != NULL)
		{
			Head->Prv = NULL;
		}
		free(Temp);
		_Size--;
	}
	void DeleteLastNode()
	{

		if (Head == NULL)return;

		if (Head->Next == NULL)
		{
			Head = NULL;
			free(Head);
			_Size--;
			return;
		}

		Node* Current = Head;
		while (Current->Next->Next != NULL)
		{
			Current = Current->Next;
		}
		Node* Temp = Current->Next;
		Current->Next = NULL;
		free(Temp);
		_Size--;
	}
	int Size()
	{
		return _Size;
	}
	bool IsEmpty()
	{
		return _Size == 0;
	}
	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}
	void Reverse()
	{
		Node* Current = Head;
		Node* Temp = nullptr;
		while (Current != nullptr)
		{
			Temp = Current->Prv;
			Current->Prv = Current->Next;
			Current->Next = Temp;
			Current = Current->Prv;
		}
		if (Temp != nullptr)
			Head = Temp->Prv;
	}
	Node* GetNode(int Index)
	{
		int Counter = 0;
		if (Index > _Size-1  || Index < 0)
			return NULL;

		Node* Current = Head;

		while (Current != NULL && Current->Next != NULL)
		{
			if (Counter == Index)
				break;
			Current = Current->Next;
			Counter++;
		}
		return Current;

	}
	T GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->Value;
	}
	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index);
		if (ItemNode != NULL)
		{
			ItemNode->Value = NewValue;
			return true;
		}
		else
			return false;
	}
	void InsertAfter(T Index, T NewValue)
	{
			Node* ItemNode = GetNode(Index);

			if (ItemNode != NULL)
			{
				InsertAfter(ItemNode, NewValue);
			}
    }
	void PrintList()
	{
		Node *Current = Head;
		while (Current != NULL)
		{
			cout << Current->Value << " ";
			Current = Current->Next;	
		}
		cout << "\n";
	}
};

