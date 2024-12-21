#pragma once
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsCurrency.h"
class clsUpdateCurrencyRateScreen:protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "\n_________________________________________";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$)=  : " << Currency.GetRate();
        cout << "\n_________________________________________\n";
    }
    float static _ReadRateCurrency()
    {
        float Rate = 0;

        cout << "\nPlease New Rate:";
        cin >> Rate;
        return Rate;
    }
public:
    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\tUpadet Currency Screen");

        cout << "\nPlease enter Currency Code?";
      string CurrencyCode= clsInputValidate::ReadString();
      while (!clsCurrency::IsCurrencyExist(CurrencyCode))
      {
          cout << "\nCurrency Code isn't Found choose another one";
          CurrencyCode = clsInputValidate::ReadString();
      }
      clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
      _PrintCurrency(Currency);

      char Answer = 'n';
      cout << "\nare you sure you want update the rate of this currency y/n?";
      cin >> Answer;

      if (Answer == 'y' || Answer == 'Y')
      {
          cout << "\n\nUpdate Currency Rate:";
          cout << "\n______________________\n";

        Currency.UpdateRate(_ReadRateCurrency());

        cout << "\nCurrency Rate Updated Successfuly:-)\n";
        _PrintCurrency(Currency);
      }

    }
};

