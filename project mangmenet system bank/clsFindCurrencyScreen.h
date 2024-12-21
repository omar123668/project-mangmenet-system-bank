#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidation.h"
class clsFindCurrencyScreen:protected clsScreen
{
private:
   static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "\n_________________________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$)=  : " << Currency.GetRate();
        cout << "\n_________________________________________\n";
    }
   static void _ShowResults(clsCurrency Currency)
   {
       if (!Currency.IsEmpty())
       {
           cout << "\nCurrency Found:-)\n";
           _PrintCurrency(Currency);
       }
       else
       {
           cout << "\nCurrency is not Found :-(\n";
       }
   }

public:
    static void ShowFindCurrrencyScreen()
    {
        _DrawScreenHeader("\tFind Currency Screen");
     

        int Number = 0;

        cout << "\nFind By: [1] Code Or [2] Country?";
        cin >> Number;
        if (Number == 1)
        {

            string CurrencyCode = "";
            cout << "\nPlease enter CurrencyCode?";
            CurrencyCode = clsInputValidate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string CountryName = "";
            cout << "\nPlease enter CountryName?";
            CountryName = clsInputValidate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
            _ShowResults(Currency);
        }
    }
};

