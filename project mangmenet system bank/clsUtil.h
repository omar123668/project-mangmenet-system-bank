#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"
using namespace std;
class clsUtil
{

public:
	enum enchartype {
		SmallLetter = 1, CapitalLetter = 2
		, Digit = 3, MixChars = 4, SpecialCharacter = 5
	};

	static int RandomNumber(int From, int To)
	{
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static char GetRandomCharacter(enchartype CharType)
	{
		if (CharType == enchartype::MixChars)
		{
			CharType = (enchartype)RandomNumber(1, 3);
		}
		switch (CharType)
		{
		case enchartype::SmallLetter:
			return (char)RandomNumber(97, 122);
			break;

		case enchartype::CapitalLetter:
			return (char)RandomNumber(65, 90);
			break;
		case enchartype::SpecialCharacter:
			return (char)RandomNumber(32, 47);
			break;
		case enchartype::Digit:
			return (char)RandomNumber(48, 57);
			break;
		}
	}
	static string GenerateWord(enchartype CharType, short Length)
	{
		string Word = "";
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey(enchartype CharType)
	{
		string Key;
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}
	static void GenerateKeys(enchartype CharType, int NumberOfKeys)
	{
		cout << endl;
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "key " << "[" << i << "] " << ":"
				<< GenerateKey(CharType) << endl;
		}
	}
	static string Encryption(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length()-1; i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}
	static string Decryption(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length()-1; i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

	static void Swab(int& A, int& B)
	{
		int Swab = 0;
		Swab = A;
		A = B;
		B = Swab;
	}
	static void Swab(double& A, double& B)
	{
		double Swab = 0;
		Swab = A;
		A = B;
		B = Swab;
	}
	static void Swab(string& A, string& B)
	{
		string Swab = "";
		Swab = A;
		A = B;
		B = Swab;
	}
	static void Swab(clsDate& A, clsDate& B)
	{
		clsDate Swab;
		Swab = A;
		A = B;
		B = Swab;
	}
	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i <= arrLength - 1; i++)
		{
			Swab(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	static  void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i <= arrLength - 1; i++)
		{
			Swab(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}
	static   void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);

		}
	}
	static   void FillArrayWithRandomWords(string arr[100], int arrLength, enchartype Chartype, int LengthWord)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(Chartype, LengthWord);

		}
	}
	static   void FillArrayWithRandomKeys(string arr[100], int arrLength, enchartype Chartype)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(Chartype);

		}
	}
	static  string Tybs(short NumberOfTyps)
	{

		string T = "";
		for (int i = 1; i <= NumberOfTyps; i++)
		{

			T = T + "\t";


		}
		return T;


	}
	static string  NumberToString(long long  Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string SmallNumber[] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve",
			"Thirteen","Forteen","Fifteen","Sixteen","Seventeen","Eigthteen","Nineteen" };
			return SmallNumber[Number - 1] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string Decedes[] = { "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return Decedes[Number / 10 - 2] + " " + NumberToString(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One Hundreds " + NumberToString(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToString(Number / 100) + "Hundreds " + NumberToString(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToString(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToString(Number / 1000) + "Thousand " + NumberToString(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return NumberToString(Number / 1000000) + "Million " + NumberToString(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToString(Number / 1000000) + "Million " + NumberToString(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return NumberToString(Number / 1000000000) + "Billion " + NumberToString(Number % 1000000000);
		}
		else
		{
			return NumberToString(Number / 1000000000) + "Billion " + NumberToString(Number % 1000000000);
		}
	}



};



