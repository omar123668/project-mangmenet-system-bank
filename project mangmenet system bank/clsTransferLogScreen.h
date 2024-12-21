#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iostream>
using namespace std;
class clsTransferLogScreen:protected clsScreen
{
public:
    static void _PrintRecord(clsBankClient::stTranferLogRecord TransferLogRecord)
    {
        cout <<setw(8)<<"" << left << "| " << setw(20) << TransferLogRecord.DateTime
            << "| " << setw(12) << left << TransferLogRecord.SourceAcountNumber
            << "| " << setw(12) << left << TransferLogRecord.DestinationAccountNumber
            << "| " << setw(12) << left << TransferLogRecord.Amount
            << "| " << setw(12) << left << TransferLogRecord.SrcBalanceAfter
            << "| " << setw(12) << left << TransferLogRecord.DestBalanceAfter
            << "| " << setw(12) << left << TransferLogRecord.UserName;
    }
public:
    static void ShowTransferLogScreen()
    {
        vector<clsBankClient::stTranferLogRecord>vTransferLogRecord = clsBankClient::GetTransferLogList();
     
        string Title = "\t Transfer Log List Screen";
        string Subtatle = "\t (" + to_string(vTransferLogRecord.size()) + " Record(s)";
        _DrawScreenHeader(Title,Subtatle);

        cout << setw(8) << "" << "\n\t__________________________________________________________________";
        cout << "_______________________________________\n";

        cout << setw(8) << "" << "| " << left << setw(20) << "DateTime";
        cout << "| " << left << setw(12) << "S.Acct";
        cout << "| " << left << setw(12) << "D.Acct";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(12) << "S.Balance";
        cout << "| " << left << setw(12) << "D.Balance";
        cout << "| " << left << setw(12) << "UserName\n";
        cout << setw(8) << "" << "\n\t__________________________________________________________________";
        cout << "_______________________________________\n";

        if(vTransferLogRecord.size()==0)
        {
            cout << "\n\t\t\t\tNo Tranfer Log Available In The System!\n";
        }

        for (clsBankClient::stTranferLogRecord TransferRecord : vTransferLogRecord)
        {
            _PrintRecord(TransferRecord);
            cout << endl;
        }
        cout << setw(8) << "" << "\n\t__________________________________________________________________";
        cout << "_______________________________________\n";
    }
};

