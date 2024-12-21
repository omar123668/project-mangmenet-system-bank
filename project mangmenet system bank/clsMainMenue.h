#pragma once
#include"clsLoginRegisterScreen.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
#include"clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include"clsDeletedClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsMangerUserScreen.h"
#include"clsCurrencyExchange.h"
#include"globaly.h"
#include<iomanip>
#include<iostream>
using namespace std;
class clsMainMenue:protected clsScreen
{
private:
    enum enMainMenueOptions
    {
        eListClients = 1, eAddNewClient = 2,
        eDeleteClient = 3, eUpdateClinet = 4,
        eFindClinet = 5, eShowTransactionsMenue = 6,
        eMangerUsers = 7,eLoginRegister=8,eCurrencyExchange=9,
        eExit = 10
    };
    static short _ReadMainMenueOpetion()
    {
       short Choice = 0;
       cout<<setw(37)<<left<<  "" << "Choice What do you want to do? [1 to 10 ]? ";
       Choice=clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number Between 1 and 10");
       return Choice;
    }
    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }
    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }
    static void _ShowDeleteClientScreen()
    {
        clsDeletedClientScreen::ShowDeletedClientScreen();
    }
    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpadteClientScreen();
    }
    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }
    static void _ShowTransactionsMenueMain()
    {
        clsTransactionsScreen::ShowTransactionsMenueMain();
    }
    static void _ShowMangerUsers()
    {
        clsMangerUserScreen::ShowMangerUsersMenue();
    }
    static void _LoginOut()
    {
        CurrentUser = clsUser::Find("", "");
    }
    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRecord();
    }
    static void _ShowCurrencyExchangeMainMenueScreen()
    {
        clsCurrencyExchangeMainMenue::ShowCurrencyExchangeMenue();
    }
   static void   _GoBackToMainMenue()
   {
        cout << "\n\nPress any key to go back to Show Menue...";
        system("pause>=0");
        ShowMainMenue();
   
   }
   static void _PerformMainMenueOpetion(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eUpdateClinet:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eFindClinet:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenueMain();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eMangerUsers:
        {
            system("cls");
            _ShowMangerUsers();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eLoginRegister:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        }
        case enMainMenueOptions::eCurrencyExchange:
        {
          system("cls");
          _ShowCurrencyExchangeMainMenueScreen();
          _GoBackToMainMenue();
          break;
        }
        case enMainMenueOptions::eExit:
        {
            system("cls");
            _LoginOut();
        }
        }
    }
public:
   static  void ShowMainMenue()
   {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "======================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue::\n";
        cout << setw(37) << left << "" << "======================================\n";
        cout << setw(37) << left << "" << "\t[1]Show Client List..\n";
        cout << setw(37) << left << "" << "\t[2]Add New Client..\n";
        cout << setw(37) << left << "" << "\t[3]Delete Client..\n";
        cout << setw(37) << left << "" << "\t[4]Update Client Info..\n";
        cout << setw(37) << left << "" << "\t[5]Find Client..\n";
        cout << setw(37) << left << "" << "\t[6]Transactions..\n";
        cout << setw(37) << left << "" << "\t[7]Manger User..\n";
        cout << setw(37) << left << "" << "\t[8]Login Register\n";
        cout << setw(37) << left << "" << "\t[9]Currency Exchange\n";
        cout << setw(37) << left << "" << "\t[10]Logout.\n";
        cout << setw(37) << left << "" << "======================================\n";
        _PerformMainMenueOpetion(enMainMenueOptions(_ReadMainMenueOpetion()));
   }
};

