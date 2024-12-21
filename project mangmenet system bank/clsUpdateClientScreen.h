#pragma once
#include "clsInputValidation.h"
#include"clsClientListScreen.h"
class clsUpdateClientScreen : protected clsScreen
{

private:
   static  void _ReadClientInfo(clsBankClient& Client)
   {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();
        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "\nEnter AccountBalance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
   }
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

    static void ShowUpadteClientScreen()
    {
        if (!CheckAccessRights(clsUser::pUpdateClient))
        {
            return;
        }
           _DrawScreenHeader("\tUpdate Client Screen");

            cout << "\nPlease enter client Account Number: ";
            string AccountNumber = clsInputValidate::ReadString();
            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nAccount Number is not Found, choose another one: ";
                AccountNumber = clsInputValidate::ReadString();
            }
            clsBankClient Client = clsBankClient::Find(AccountNumber);
            _PrintClient(Client);
        
            _ReadClientInfo(Client);

            clsBankClient::enSaveResults saveResult = Client.Save();
            switch (saveResult)
            {
            case clsBankClient::svSucceeded:
            {
                cout << "\nAccout Updated Successfuly:-)\n";
                _PrintClient(Client);
                break;
            }
            case clsBankClient::svFaildEmptyObject:
            {
                cout << "\nError account was not saved becuase it's Empty";
                break;
            }
            case clsBankClient::svFaildAccountNumberExists:
            {
                cout << "\nError account was Not saved becuase account already used:-(";
            }
            }
    }

};

