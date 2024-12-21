#pragma once
#include"clsTransferScreen.h"
#include "clsInputValidation.h"
#include "clsScreen.h"
#include"clsDepositeScreen.h"
#include<iomanip>
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;
class clsTransactionsScreen:protected clsScreen
{
private:
    enum enTransactionsMenueOptions
    {
        eDeposite = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eShowTransfer=4,eShowTranferLog=5,
        eShowMainMenue = 6,
    };

    static   short ReadTransactionsMenueMain()
    {
        short Choice = 0;
        cout << setw(37) << left << "" << "Choice What do you want to do? [1 to 5 ]? ";
      Choice=  clsInputValidate::ReadIntNumberBetween(1, 6, "Enter a Number Between 1 and 5");
      return Choice;
    }
     static void  _ShowDepositeScreen()
     {
         clsDepositeScreen::ShowDepositScreen();
     }
     static void _ShowWithdrawScreen()
     {
         clsWithdrawScreen::ShowWithdrawScreen();
     }
     static void _ShowTotalBalancesScreen()
     {
         clsTotalBalanceScreen::ShowTotalBalances();
     }
     static void _ShowTransferScreen()
     {
         clsTransferScreen::ShowTransferScreen();
     }
     static void _ShowTranferLogScreen()
     {
         clsTransferLogScreen::ShowTransferLogScreen();
    }
      static void _GoBackToTransactionsMenue()
      {
        cout << "\n\nPress any key to go back to transactions Menue...";
        system("pause>=0");
        ShowTransactionsMenueMain();
      }
   static  void _PerformTransactionsMenueChoice(enTransactionsMenueOptions TransactionMenueMain)
    {

        switch (TransactionMenueMain)
        {
        case enTransactionsMenueOptions::eDeposite:
        {
            system("cls");
            _ShowDepositeScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case clsTransactionsScreen::eShowTransfer:
        {
             system("cls");
             _ShowTransferScreen();
             _GoBackToTransactionsMenue();
             break;
        }
        case enTransactionsMenueOptions::eShowTranferLog:
        {       
            system("cls");
            _ShowTranferLogScreen();
            _GoBackToTransactionsMenue();
             break;
        }
        case enTransactionsMenueOptions::eShowMainMenue:
        {
           
        }
        }
    }
public:
   static void ShowTransactionsMenueMain()
    {
       if (!CheckAccessRights(clsUser::pTransactions))
       {
           return;
       }
       system("cls");
       _DrawScreenHeader("\t Transactions Screen");

       cout << setw(37) << left << "" << "=========================================\n";
       cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
       cout << setw(37) << left << "" << "=========================================\n";
       cout << setw(37) << left << "" << "\t\t[1] Deposit.\n";
       cout << setw(37) << left << "" << "\t\t[2] Withdraw.\n";
       cout << setw(37) << left << "" << "\t\t[3] Total Balance.\n";
       cout << setw(37) << left << "" << "\t\t[4] Transfer.\n";
       cout << setw(37) << left << "" << "\t\t[5] Transfer Log.\n";
       cout << setw(37) << left << "" << "\t\t[6] Menue Main.\n";
       cout << setw(37) << left << "" << "=========================================\n";
        _PerformTransactionsMenueChoice(enTransactionsMenueOptions(ReadTransactionsMenueMain()));
    }
};

