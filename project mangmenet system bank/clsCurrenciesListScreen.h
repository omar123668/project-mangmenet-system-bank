#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
class clsCurrenciesListScreen:protected clsScreen
{
private:
   static void _PrintCurrencyRecordLine(clsCurrency& Currency)
    {
        cout << setw(8) << "" << left << "| " << setw(30) << left << Currency.Country()
        << "| " << setw(8) << left << Currency.CurrencyCode()
        << "| " << setw(45) << left << Currency.CurrencyName() 
        << "| " <<setw(10)<<left<< Currency.GetRate();
    }
public:
    static void ShowCurrenciesListScreen()
    {

        vector<clsCurrency>vCurrencies = clsCurrency::GetCurrencyList();
        string Title = "\t Currencies List Screen";
        string Subtitle = "\t (" + to_string(vCurrencies.size()) + ") Currencies.";
        _DrawScreenHeader(Title,Subtitle);

        cout << setw(8) << "" << left << "\n\t__________________________________________________________________";
        cout << "______________________________________\n";
        cout << setw(8) << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";

        cout << setw(8) << "" << left << "\n\t__________________________________________________________________";
        cout << "______________________________________\n";
        if (vCurrencies.size() == 0)
        {
            cout << "\n\t\t\t\tNo Currencies Available In The System!\n";
        }
        for (clsCurrency Currencies : vCurrencies)
        {
            _PrintCurrencyRecordLine(Currencies);
            cout << endl;
        }
        cout << setw(8) << "" << left << "\n\t__________________________________________________________________";
        cout << "______________________________________\n";
    }
};

