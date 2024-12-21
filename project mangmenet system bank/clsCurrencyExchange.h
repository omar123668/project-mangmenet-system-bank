#pragma once
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidation.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainMenue:protected clsScreen
{
private:
    enum enCurrencyExchange{eListCurrencies=1,eFindCurrency=2,eUpdateRate=3,eCurrencyCalculator=4,eMainMenue=5};
   static short _ReadCurrrenciesMainMenueOptions()
    {
        short Choice = 0;
        cout << setw(37) << left << "" << "Choice What do you want to do? [1 to 5 ]? ";
        Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number Between 1 and 5");
        return Choice;
    }
    static void _ShowCurrenciesListScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrrencyScreen();

    }
    static void _ShowCUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    static void   _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to  Currencies Menue...";
        system("pause>=0");
        ShowCurrencyExchangeMenue();

    }
    static void _PerformCurrenciesMainMenueOptions(enCurrencyExchange CurrenciesMenueMainOptions)
    {

        switch (CurrenciesMenueMainOptions)
        {
        case enCurrencyExchange::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenue();
            break;
        }
            
        case enCurrencyExchange::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
            break;
        }
        case enCurrencyExchange::eUpdateRate:
        {
            system("cls");
            _ShowCUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenue();
            break;
        }
        case enCurrencyExchange::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenue();
            break;
        }
        case enCurrencyExchange::eMainMenue:
        {

        }


        }
    }
public:
    static  void ShowCurrencyExchangeMenue()
    {
        system("cls");
        _DrawScreenHeader(" Currency Exchange Main Screen");
        cout << setw(37) << left << "" << "======================================\n";
        cout << setw(37) << left << "" << "\tCurrency Exchange Menue::\n";
        cout << setw(37) << left << "" << "======================================\n";
        cout << setw(37) << left << "" << "\t[1]List Currencies..\n";
        cout << setw(37) << left << "" << "\t[2]Find Currency..\n";
        cout << setw(37) << left << "" << "\t[3]Update Rate..\n";
        cout << setw(37) << left << "" << "\t[4]Currency Calculator..\n";
        cout << setw(37) << left << "" << "\t[5]Main Menue..\n";
        cout << setw(37) << left << "" << "======================================\n";
        _PerformCurrenciesMainMenueOptions(enCurrencyExchange(_ReadCurrrenciesMainMenueOptions()));
    }

};

