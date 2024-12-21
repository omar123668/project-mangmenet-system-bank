#pragma once
#include<iostream>
#include"clsString.h"
#include<string>
#include<fstream>
using namespace std;
class clsCurrency
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string>vCurrency=clsString::SplitEachWordInVector(Line, Seperator);

	 return	clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2],stof(vCurrency[3]));

	}
	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string stCurrencyData = "";
		stCurrencyData += Currency._Country + Seperator;
		stCurrencyData += Currency._CurrencyCode + Seperator;
		stCurrencyData += Currency._CurrencyName + Seperator;
		stCurrencyData += to_string(Currency._Rate) + Seperator;
		return stCurrencyData;
	}
	static vector<clsCurrency>_LoadCurreencysDataFromFile()
	{
		vector<clsCurrency>vCurrencys;
		fstream MyFile;
		MyFile.open("Currencys.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencys.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencys;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrencys)
	{
		fstream myfile;
		myfile.open("Currencys.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsCurrency C : vCurrencys)
			{
				string stDataLine = _ConvertCurrencyObjectToLine(C);
				myfile << stDataLine << endl;
			}
			myfile.close();
		}
	}
	void _Update()
	{
		vector<clsCurrency>_vCurrencys = _LoadCurreencysDataFromFile();
		for (clsCurrency c : _vCurrencys)
		{
			if (c.CurrencyCode() == _CurrencyCode)
			{
				c = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrencys);
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public:
	clsCurrency(enMode _Mode, string _Country, string _CurrencyCode, string _CurrencyName, float _Rate)
	{
		this->_Mode = _Mode;
		this->_Country = _Country;
		this->_CurrencyCode = _CurrencyCode;
		this->_CurrencyName = _CurrencyName;
		this->_Rate = _Rate;
	}
	static vector<clsCurrency>GetAllUSDRates()
	{
		return _LoadCurreencysDataFromFile();
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	void UpdateRate(float NewRate)
	{
		this->_Rate = NewRate;
		_Update();
	}
	float GetRate()
	{
		return this->_Rate;
	}
	bool IsEmpty()
	{
		return enMode::EmptyMode == _Mode;
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllLettersOfAString(CurrencyCode);
		fstream myfile;
		myfile.open("Currencys.txt", ios::in);
		if (myfile.is_open())
		{
			string Line;
			while (getline(myfile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					myfile.close();
			        return Currency;
				}
			}
			myfile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string CurrencyName)
	{
		fstream myfile;
		myfile.open("Currencys.txt", ios::in);
		if (myfile.is_open())
		{
			string Line;
			while (getline(myfile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllLettersOfAString(Currency.Country()) == clsString::UpperAllLettersOfAString(CurrencyName))
				{
					myfile.close();
					return Currency;
				}
			}
			myfile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}
	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadCurreencysDataFromFile();
	}
	static clsCurrency GetEmptyCurrencyObject()
	{
		return _GetEmptyCurrencyObject();
	}
	 float ConvertToUSD(float Amount)
	{

		 return (float)(Amount / GetRate());
	}
	 float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	 {

		 float AmountInUSD = ConvertToUSD(Amount);
		 if (Currency2.CurrencyCode() == "USD")
		 {
			 return AmountInUSD;
		 }
		 return (float)(AmountInUSD * Currency2.GetRate());


	 }
};

