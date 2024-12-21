#pragma once
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsCurrency.h"
class clsCurrencyCalculatorScreen:protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency,string Title="Currency Card")
    {
        cout << "\n" << Title << "\n";
        cout << "\n_________________________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$)=  : " << Currency.GetRate();
        cout << "\n_________________________________________\n\n";
    }
    static  clsCurrency _GetCurrency(string Message)
    {
        string CurrencyCode = "";
        cout << Message << endl;
        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Code isn't Found choose another one";
            CurrencyCode = clsInputValidate::ReadString();
        }
       clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
       return Currency;
    }
    static void _PrintCalculationsResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
    {
        _PrintCurrencyCard(CurrencyFrom, "Convert From:");
        float AmountUsd = CurrencyFrom.ConvertToUSD(Amount);
    

        cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountUsd << " " << "USD" << "\n";

        if (CurrencyTo.CurrencyCode() == "USD")
        {
            return;
        }

         cout << "\nConverting from USD TO:\n";
        _PrintCurrencyCard(CurrencyTo,"To");
        float AmountInCurrency2= CurrencyFrom.ConvertToOtherCurrency(Amount,CurrencyTo);

        cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrency2 <<" " <<CurrencyTo.CurrencyCode();
    }
    static float _ReadAmountExchange()
    {
        float Amount = 0;
        cout << "\nEnter Amount To Exchange: ";
        Amount=  clsInputValidate::ReadFloatNumber();
        return Amount;
    }
public:
    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';
        while (toupper(Continue)=='Y')
        {
            system("cls");
            _DrawScreenHeader("\tCurrency Calculator");

            clsCurrency CurrencyFrom = _GetCurrency("\nPlease enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease enter Currency2 Code");
            float Amount = _ReadAmountExchange();
            _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want To perform another calculator? y/n? ";
            cin >> Continue;
        }
    }

};

