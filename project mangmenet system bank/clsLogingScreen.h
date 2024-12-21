#pragma once
#include"clsMainMenue.h"
class clsLogingScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;
		string UserName, Password;
		do
		{

			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvalide UserName/Password!";
				cout << "\nYou Have " <<3-FaildLoginCount <<
					" Trail (s) to login.\n\n";
			}
			if (FaildLoginCount == 3)
			{
				cout << "\n\nYour are Locked after 3 Faild trails.";
				return false;
			}
			cout << "\n\nEnter UserName?";
  			cin >> UserName;
			cout << "Enter Password?";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
			
			
		} while(LoginFaild);
		CurrentUser.RegisterLogin();
		clsMainMenue::ShowMainMenue();
		return true;
	}
public:
	static bool  ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};

