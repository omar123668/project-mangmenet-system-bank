#pragma once
#include"iostream"
#include "clsInputValidation.h"
#include<iomanip>
#include"clsScreen.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsUpdateUserScreen.h"
using namespace std;
class clsMangerUserScreen:protected clsScreen
{
private:
    enum enMangerUsersMenueOptions
    {
        eListUsers  = 1, eAddNewUser  = 2
       ,eDeleteUser = 3, eUpdateUser  = 4,
        eFindUser   = 5,
        eMainMenue   = 6
    };
    static short _ReadMangerUsersMnueOption()
    {
        short Choice = 0;
        cout << setw(37) << left << "" << "Choice What do you want to do? [1 to 6 ]? ";
        Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter a Number Between 1 and 6");
        return Choice;
    }
    static void  _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowAllUserScreen();
    }
    static void  _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void  _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeletedClientScreen();
    }
    static void  _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpadteUserScreen();

    }
    static void  _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformMangerUsersMenueOptions(enMangerUsersMenueOptions MangerUsersMenueOption)
    {
        switch (MangerUsersMenueOption)
        {
        case enMangerUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToMangerUsersMenue();
            break;
        }
        case enMangerUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToMangerUsersMenue();
            break;

        }
        case enMangerUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToMangerUsersMenue();
            break;


        }
        case enMangerUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToMangerUsersMenue();
            break;

        }
        case enMangerUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToMangerUsersMenue();
            break;
        }
        case enMangerUsersMenueOptions::eMainMenue:
        {

        }

        }
    }
    static void _GoBackToMangerUsersMenue()
    {
            cout << "\n\nPress any Key to go back to Manger User...";
            system("pause>=0");
            ShowMangerUsersMenue();
    }
public:

    static void ShowMangerUsersMenue()
    {
        if (!CheckAccessRights(clsUser::pMangerUsers))
        {
            return;
        }
        system("cls");
    
        _DrawScreenHeader("\t  Manger Users Screen");

        cout << setw(37) << left << "" << "========================================\n";
        cout << setw(37) << left << "" << "\t\t\tManger Users.\n";
        cout << setw(37) << left << "" << "========================================\n";
        cout << setw(37) << left << "" << "\t[1]List Users.\n";
        cout << setw(37) << left << "" << "\t[2]Add New User.\n";
        cout << setw(37) << left << "" << "\t[3]Delete User.\n";
        cout << setw(37) << left << "" << "\t[4]Update User.\n";
        cout << setw(37) << left << "" << "\t[5]Find User.\n";
        cout << setw(37) << left << "" << "\t[6]Main Menue.\n";

        cout << setw(37) << left << "" << "========================================\n";
        _PerformMangerUsersMenueOptions(enMangerUsersMenueOptions(_ReadMangerUsersMnueOption()));
    }
};

