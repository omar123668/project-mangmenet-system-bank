#pragma once
#include<iomanip>
#include"clsScreen.h"
using namespace std;
class clsLoginRegisterScreen:protected  clsScreen
{
private:
	static void _PrintLoginRecord(clsUser::stLoginRegisterRecord U)
	{
        cout << setw(8) << "" << "| " << setw(35) << left << U.DateTime;
        cout << "| " << setw(20) << left << U.UserName;
        cout << "| " << setw(20) << left << U.Password;
        cout << "| " << setw(20) << left << U.Permissions;
	}
public:
    static void ShowLoginRecord()
    {
        if (!CheckAccessRights(clsUser::pShowLoginRegister))
        {
            return;
        }
        vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecord = clsUser::GetLoginRegisterList();
        string Title = "\t Login Register List Screen";
        string Subtitle = "\t (" + to_string(vLoginRegisterRecord.size()) + ") Record (s).";
         _DrawScreenHeader(Title, Subtitle);
         cout << setw(8) << "" << left << "\n\t_____________________________________________________________________"
             << "___________________________\n\n";
   
        cout << setw(8) << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
        cout << setw(8) << "" << left << "\n\t_____________________________________________________________________"
            << "___________________________\n\n";
     
    
        if (vLoginRegisterRecord.size() == 0)
        {
            cout << "\n\t\t\t\tNo Logins Available In The System!\n";
        }
        for (clsUser::stLoginRegisterRecord c : vLoginRegisterRecord)
        {
            _PrintLoginRecord(c);
            cout << endl;
        }
        cout << setw(8) << "" << "_______________________________________________________________________"
            << "___________________________\n\n";

    }


};

