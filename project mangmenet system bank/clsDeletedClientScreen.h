#pragma once
#include"clsClientListScreen.h"
#include"clsInputValidation.h"
class clsDeletedClientScreen:protected clsScreen
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
    static void ShowDeletedClientScreen()
    {
        if (!CheckAccessRights(clsUser::pDeleteClient))
        {
            return;
        }
           _DrawScreenHeader("\tDelete Client Screen");
       
            cout << "\nPlease enter client Account Number: ";
            string AccountNumber = clsInputValidate::ReadString();
            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nAccount Number isn't  found choose another one: ";
                AccountNumber = clsInputValidate::ReadString();
            }
            clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);
            _PrintClient(DeleteClient);
            cout << "\nAre you sure you want to delelte this client y/n? ";
            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            {

                if (DeleteClient.Delete())
                {
                    cout << "\nClient Deleted Successfuly :-)" << endl;
                    _PrintClient(DeleteClient);
                }
                else
                    cout << "\nError Client Was Not Deleted\n";
            }
    }

};

