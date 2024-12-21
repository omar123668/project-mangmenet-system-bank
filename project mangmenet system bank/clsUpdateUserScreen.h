#pragma once
#include "clsInputValidation.h"
#include"clsScreen.h"
//#include"clsUser.h"
class clsUpdateUserScreen:protected clsScreen
{
private:
        static  void _ReadUserInfo(clsUser& User)
        {
            cout << "\nEnter FirstName: ";
            User.FirstName = clsInputValidate::ReadString();
            cout << "\nEnter LastName: ";
            User.LastName = clsInputValidate::ReadString();
            cout << "\nEnter Email: ";
            User.Email = clsInputValidate::ReadString();
            cout << "\nEnter Phone: ";
            User.Phone = clsInputValidate::ReadString();
            cout << "\nEnter Password: ";
            User.Password = clsInputValidate::ReadString();
            cout << "\nEnter Permission: ";
            User.Permissions = _ReadPermissionToSet();
        }
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
        static int _ReadPermissionToSet()
        {
            char Answer = 'n';
            int Permission = 0;
            cout << "\n\nDo you want to give full access? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                return -1;
            }
            cout << "\n[1] Show User List? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permission += clsUser::enPermissions::pListClient;
            }
            cout << "\n[2] Add New User? y/n? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permission += clsUser::enPermissions::pNewClient;
            }
            cout << "\n[3] Delete User? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permission += clsUser::enPermissions::pDeleteClient;
            }
            cout << "\n[4] Update User? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permission += clsUser::enPermissions::pUpdateClient;
            }
            cout << "\n[5] Find User? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permission += clsUser::enPermissions::pFindClient;
            }
            cout << "\n[6] Transactions? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permission += clsUser::enPermissions::pTransactions;
            }
            cout << "\n[7] Manger Users? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permission += clsUser::enPermissions::pMangerUsers;
               
            }
            cout << "\n[8]Show Login Register? ";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permission += clsUser::pShowLoginRegister;
                return Permission;
            }
            return Permission;
        }
    public:

        static void ShowUpadteUserScreen()
        {
            _DrawScreenHeader("\tUpdate User Screen");

            cout << "\nPlease enter UserName: ";
            string UserName = clsInputValidate::ReadString();
            while (!clsUser::IsUserExist(UserName))
            {
                cout << "\nUserName is not Found, choose another one: ";
                UserName = clsInputValidate::ReadString();
            }
            clsUser User = clsUser::Find(UserName);
            _PrintUser(User);

            _ReadUserInfo(User);

            clsUser::enSaveResults saveResult = User.Save();
            switch (saveResult)
            {
            case clsUser::svSucceeded:
            {
                cout << "\nUser Updated Successfuly:-)\n";
                _PrintUser(User);
                break;
            }
            case clsUser::svFaildEmptyObject:
            {
                cout << "\nError account was not saved becuase it's Empty";
                break;
            }
            case clsUser::svFaildUserExists:
            {
                cout << "\nError account was Not saved becuase account already used:-(";
            }
            }
        }
};

