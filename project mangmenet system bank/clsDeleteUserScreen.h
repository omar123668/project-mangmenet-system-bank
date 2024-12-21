#pragma once
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidation.h"
class clsDeleteUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser& User)
    {

        cout << "\nCard User";
        cout << "\n================================\n";
        cout << "\nFirstName      : " << User.FirstName;
        cout << "\nLastName       : " << User.LastName;
        cout << "\nFullName       : " << User.FullName();
        cout << "\nEmail          : " << User.Email;
        cout << "\nUserName       : " << User.GetUserName();
        cout << "\nPassword       : " << User.Password;
        cout << "\nPermissions    : " << User.Permissions;
        cout << "\n================================\n";
    }
public:
    static void ShowDeletedClientScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");

        cout << "\nPlease enter UserName: ";
        string UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName isn't  found choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser DeleteUser = clsUser::Find(UserName);
        _PrintUser(DeleteUser);
        cout << "\nAre you sure you want to delete this User y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {

            if (DeleteUser.Delete())
            {
                cout << "\nUser Deleted Successfuly :-)" << endl;
                _PrintUser(DeleteUser);
            }
            else
                cout << "\nError Client Was Not Deleted\n";
        }
    }

};

