#pragma once
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsUser.h"
class clsFindUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser& User)
    {
        cout << "================================";
        cout << "\nCard User";
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
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");
        cout << "\nPlease enter UserName: ";
        string UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName isn't  found choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
            cout << "\nUser Found:-)\n";
        }
        else
        {
            cout << "\nUser Was Not Found:-(\n";
        }

        _PrintUser(User);
    }
};

