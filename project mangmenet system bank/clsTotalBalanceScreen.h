#pragma once
#include"clsClientListScreen.h"
#include "clsInputValidation.h"
#include"clsScreen.h"
#include "clsUtil.h"
class clsTotalBalanceScreen:protected clsScreen
{
private:
    static void PrintClientRecordBalance(clsBankClient& Client)
    {
        cout << setw(25) << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }
public:
    static void ShowTotalBalances()
    {
        vector<clsBankClient>vClients = clsBankClient::GetClientsList();
        string Title = "\t Balance List Screen";
        string SubTitle = "\t ("+  to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << "" <<left<< "\n\t__________________________________________________________________";
        cout << "_______________________________________\n";
        cout << setw(25) << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Account Balance\n";

        cout << setw(25) << "" << left << "\n\t__________________________________________________________________";
        cout << "_______________________________________\n";
        double TotalBalance = clsBankClient::GetTotalBalances();
        if (vClients.size() == 0)
        {
            cout << "\n\t\t\t\tNo Clients Available In The System!\n";
        }
        for (clsBankClient& Client : vClients)
        {
            PrintClientRecordBalance(Client);
            cout << endl;
        }
        cout << setw(25) << "" << left << "\n\t__________________________________________________________________";
        cout << "_______________________________________\n\n";

        cout << setw(8) << "" << left << "\t\t\t\t\t\t    Total Balance = " << TotalBalance << endl;
        cout << setw(8) << "" << left << "\t\t\t\t   ( " << clsUtil::NumberToString(TotalBalance) << ")" << endl;
    }
};

