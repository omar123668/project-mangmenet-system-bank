#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include<iomanip>
class clsClientListScreen :protected clsScreen
{
private:
    static void PrintClientRecord(clsBankClient& Client)
    {

        cout <<setw(8)<<""<< "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.GetEmail();
        cout << "| " << left << setw(10) << Client.GetPinCode();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }
public:

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::pListClient))
        {
            return;
        }
        vector<clsBankClient>vClients = clsBankClient::GetClientsList();
        string Title = "\t Client List Screen";
        string SubTitle = "\t    (" +  to_string(vClients.size()) + ") Client (s).";
        _DrawScreenHeader(Title, SubTitle);
        cout <<setw(8)<<"" << "\n\t__________________________________________________________________";
        cout << "_______________________________________\n";
        cout << setw(8) << ""<< "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "PinCode";
        cout << "| " << left << setw(12) << "Account Balance\n";
        if (vClients.size() == 0)
        {
            cout << "\n\t\t\t\tNo Clients Available In The System!\n";
        }
        for (clsBankClient& Client : vClients)
        {
            PrintClientRecord(Client);
            cout << endl;
        }
        cout << setw(8) << "" << "_________________________________________________________________";
        cout << "_______________________________________\n";

    }




};

