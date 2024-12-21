#pragma once
#include"clsInputValidation.h"
#include "clsScreen.h"
#include"clsBankClient.h"
class clsFindClientScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient& Client)
    {
        cout << "================================";
        cout << "\n""Card Client";
        cout << "\nFirstName      : " << Client.FirstName;
        cout << "\nLastName       : " << Client.LastName;
        cout << "\nFullName       : " << Client.FullName();
        cout << "\nEmail          : " << Client.Email;
        cout << "\nAcc.Number     : " << Client.AccountNumber();
        cout << "\nPinCode        : " << Client.PinCode;
        cout << "\nAcc.balance    : " << Client.AccountBalance;
        cout << "\n================================\n";
    }
public:
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::pTransactions))
        {
            return;
        }
        _DrawScreenHeader("\tFind Client Screen");
        cout << "\nPlease enter client Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number isn't  found choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
           cout << "\nClient Found:-)\n";
        }
        else
        {
            cout << "\nClient Was Not Found:-(\n";
        }

        _PrintClient(Client);
    }
};

