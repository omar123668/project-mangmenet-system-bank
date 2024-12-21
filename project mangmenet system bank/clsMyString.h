#pragma once
#include<string>
#include<stack>
using namespace std;
class clsMyString
{
private:
	stack<string>_Undo;
	stack<string>_Redo;
	string _Value;
public:
	

	void SetS1(string Value)
	{
		_Undo.push(_Value);
		_Value = Value;
	}
	string Get()
	{
		return _Value;
	}
	void Undo()
	{
		if(!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
	}
	void Redo()
	{
		if(!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}
	__declspec(property(get = Get, put = SetS1))string Value;
};

