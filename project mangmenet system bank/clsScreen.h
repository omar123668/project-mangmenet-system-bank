#pragma once
#include"globaly.h"
using namespace std;
class clsScreen
{
public:
	static void _DrawScreenHeader(string Title, string Subtitle = "")
	{
		cout << "\t\t\t\t\t__________________________________";
		cout << "\n\n\t\t\t\t\t" << Title;

		if (Subtitle != "")
		{
			cout << "\n\n\t\t\t\t\t" << Subtitle;
		}
		cout << "\n\t\t\t\t\t__________________________________" << endl << endl;
		
		cout <<setw(40) << left << ""  << "User:" << CurrentUser.UserName << endl;
		cout << setw(40) << left << ""<<  "Date:" <<clsDate::DateToString(clsDate())<< endl;

	};
	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t______________________________________________________";
			cout << "\n\n\t\t\t\t\t Access Denied! Contact your Admin";
			cout << "\n\t\t\t\t\t______________________________________________________";
			return false;
		}
		else
			return true;
	}
};

