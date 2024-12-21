#pragma once
#include"clsClientListScreen.h"
#include "clsInputValidation.h"
#include"clsScreen.h"
using namespace std;
class clsTransferScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient& Client)
    {
        cout << "\n\nCard Client";
        cout << "\n_____________________________________\n";
        cout <<"Fill Name : "<< Client.FullName() << endl;
        cout <<"Acc.Number: "<<  Client.AccountNumber() << endl;
        cout <<"Balance   : "<< Client.AccountBalance << endl;
        cout << "_____________________________________\n\n";
    }
    static string _ReadAccountNumber()
    {
        cout << "\nPlease enter Account Number To Transfer Amount  From : ";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not Found, Choose another one";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;

    }
    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount = 0;
        cout << "\nPlease enter Transfer?";
        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter Another Amonth?";
            cin >> Amount;
        }
        return Amount;
    }
public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t Transfer Screen");
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
        _PrintClient(DestinationClient);

        float Amount = _ReadAmount(SourceClient);

        char Answer = 'n';
        cout << "\nAre you sure you want to perform this Operation y/n?";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTranfer Done Successfuly\n";
            }
            else
            {
                cout << "\nTransfer Faild\n";
            }
        }
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }


};

