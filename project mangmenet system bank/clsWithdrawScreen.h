#pragma once
#pragma once
#include"clsBankClient.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
class clsWithdrawScreen:protected clsScreen
{
private:
    static string _ReadAccountNumber()
    {
        string S1 = "";
        cout << "\nPlease enter AccountNumber?";
        getline(cin >> ws, S1);
        return S1;
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

    static void ShowWithdrawScreen()
    {
        clsScreen::_DrawScreenHeader("\t Withdraw Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient With[" << AccountNumber << "] isn't Found";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease enter Withdraw?";
       Amount= clsInputValidate::ReadDblNumber();
        char Answer = 'n';
        cout << "\nAre you sure you want to perform this transactions?";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Withdraw(Amount))
            {
                cout << "\nAmount Withdraw Successfuly.\n";
                cout << "\nNew Balance Is: " << Client.GetAccountBalance();
            }
            else
            {
                cout << "\nCannot Withdraw Insuffecient Balance!\n";
                cout << "\nAmount to withdraw is:" << Amount;
                cout << "\nyour Balance is: " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperation Was cancelled.\n";
        }
    }
};

