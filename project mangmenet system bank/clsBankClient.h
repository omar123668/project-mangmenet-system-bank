#pragma once
#include <iostream>
#include<string>
#include <vector>
#include"clsString.h"
#include"clsPerson.h"
#include "clsUtil.h"
#include"globaly.h"
#include<fstream>
using namespace std;
class clsBankClient :public clsPerson
{

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool MarkForDelete = false;



	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>VclientDate;

		VclientDate = clsString::SplitEachWordInVector(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, VclientDate[0], VclientDate[1], VclientDate[2], VclientDate[3], VclientDate[4], VclientDate[5],
			stod(VclientDate[6]));

	}
	struct stTranferLogRecord;
	static stTranferLogRecord ConvertTransferLogToLine(string Line,string Seperator="#//#")
	{
		stTranferLogRecord TransferRecord;
		vector<string>vTransferLog = clsString::SplitEachWordInVector(Line,Seperator);
		TransferRecord.DateTime = vTransferLog[0];
		TransferRecord.SourceAcountNumber = vTransferLog[1];
		TransferRecord.DestinationAccountNumber = vTransferLog[2];
		TransferRecord.Amount = stof(vTransferLog[3]);
		TransferRecord.SrcBalanceAfter = stof(vTransferLog[4]);
		TransferRecord.DestBalanceAfter =stof(vTransferLog[5]);
		TransferRecord.UserName = vTransferLog[6];
		return TransferRecord;
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient>_Vclients;
		fstream Myfile;
		Myfile.open("Clients.txt");
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				_Vclients.push_back(Client);
			}
			Myfile.close();
		}
		return _Vclients;
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.GetFirstName() + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.GetAccountBalance());
		return stClientRecord;
	}
	static void _SaveClientDataToFile(vector<clsBankClient>_Vclients)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out);
		if (Myfile.is_open())
		{
			for (clsBankClient& C : _Vclients)
			{
				if (C.MarkForDelete == false)
				{
					string DateToLine = _ConvertClientObjectToLine(C);
					Myfile << DateToLine << endl;
				}
			}
			Myfile.close();
		}
	}
	static void AddDataLineToFile(string StDataLine)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << StDataLine << endl;
			Myfile.close();
		}
	}
	static void _AddTransferLogToFile(string Line)
	{
		fstream Myfile;
		Myfile.open("TransferLog.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << Line << endl;
			Myfile.close();
		}
	}
	string _PrepareTranserLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}
	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTranserLogRecord(Amount, DestinationClient, UserName);

		fstream Myfile;
		Myfile.open("TransferLog.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << stDataLine << endl;
			Myfile.close();
		}

	}
	void _AddNew()
	{
		AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	void _Update()
	{
		vector<clsBankClient>vClients;
		vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(vClients);
		return;
	}
public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccoutNumber, string PinCode,
		float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccoutNumber;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;

	}
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	void  SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = GetAccountBalance, put = SetAccountBalance))double AccountBalance;
	void Deposit(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > GetAccountBalance())
		{
			return false;
		}
		else
			AccountBalance -= Amount;
		Save();
		return true;
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client1 = _ConvertLineToClientObject(Line);

				if (Client1.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client1;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{

		case EmptyMode:
		{
			return svFaildEmptyObject;
		}
		case UpdateMode:
		{

			_Update();
			return svSucceeded;
		}
		case AddNewMode:
			
			if(clsBankClient::IsClientExist(_AccountNumber))
			{
			return svFaildAccountNumberExists;
		    }
		else
		{
			_AddNew();
			_Mode = UpdateMode;
			return svSucceeded;
		}
		}
	}


	bool Delete()
	{
		vector<clsBankClient >_Vclients;
		_Vclients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _Vclients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C.MarkForDelete = true;
				_SaveClientDataToFile(_Vclients);
				*this = _GetEmptyClientObject();
				return true;
			}
		}
		return false;
	}
	 static clsBankClient GetAddNewClientObject(string AccountNumber)
	 {
	   return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	 }
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}
	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
	static double GetTotalBalances()
	{
		vector<clsBankClient >Vclients = _LoadClientsDataFromFile();
		double TotalBalances = 0;
		for (clsBankClient& Client : Vclients)
		{
			TotalBalances += Client.GetAccountBalance();
		}
		return TotalBalances;
	}
    bool Transfer(float Amount, clsBankClient& DestinationClient,string UserName=CurrentUser.UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		else
	    Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}
	struct stTranferLogRecord
	{
		string DateTime;
		string SourceAcountNumber;
		string DestinationAccountNumber;
		float Amount;
		float SrcBalanceAfter;
		float DestBalanceAfter;
		string UserName;
	};
	static vector<stTranferLogRecord>GetTransferLogList()
	{
		vector<stTranferLogRecord>vTransferLogRecord;
		fstream myfile;
		myfile.open("TransferLog.txt", ios::in);
		if (myfile.is_open())
		{
			string Line;
			while (getline(myfile, Line))
			{
				stTranferLogRecord TransferRecord = ConvertTransferLogToLine(Line);
				vTransferLogRecord.push_back(TransferRecord);
			}
			myfile.close();
		}
		return vTransferLogRecord;
	}
};

