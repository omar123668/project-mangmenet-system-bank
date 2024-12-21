#pragma once
#include<iostream>
using namespace std;
template <typename T>
class Calculator
{
	T Num1, Num2;

public:
	Calculator(T Number1, T Number2)
	{
		Num1 = Number1;
		Num2 = Number2;
	}
	void PrintResults()
	{
		cout << "Numbers = " << Num1 << " and " << Num2 << endl << endl;
		cout << Num1 << " + " << Num2 << " = " << Add() << endl;
		cout << Num1 << " - " << Num2 << " = " << Subtract() << endl;
		cout << Num1 << " * " << Num2 << " = " << Mutiply() << endl;
		cout << Num1 << " / " << Num2 << " = " << Divide() << endl;
	}
	T Add()
	{
		return Num1 + Num2;
	}
	T Subtract()
	{
		return Num1 - Num2;
	}
	T Mutiply()
	{
		return Num1 * Num2;
	}
	T Divide()
	{
		return Num1 / Num2;
	}
};

