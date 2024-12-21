#pragma once
#include"clsScreen.h";
#include"iomanip"
#include"iostream"
#include"clsUser.h"
using namespace std;
class clsListUsersScreen :protected clsScreen
{
private:
   static void _PrintUserRecordLine(clsUser& User)
   {
        cout <<setw(8)<< left <<"" <<"| "<< setw(12)<<left << User.UserName;
        cout << "| " << left << setw(25) << left<< User.FullName();
        cout << "| " << left << setw(12) << left<< User.Phone;
        cout << "| " << left << setw(20) << left<< User.Email;
        cout << "| " << left << setw(10) << left<< User.Password;
        cout << "| " << left << setw(12) << left<< User.Permissions;
   }
public:

   static void ShowAllUserScreen()
    {
        vector<clsUser>Vusers = clsUser::GetUsersList();
        string Title = "\t User List Screen";
        string SubTitle = "\t (" + to_string(Vusers.size()) + ") Client(s).";
        _DrawScreenHeader(Title,SubTitle);
        cout << setw(8) <<""<< left << "\n\t__________________________________________________________________";
        cout << "____________________________________\n";
        cout << setw(8) << left <<"" <<"| "<<left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "FullName";
        cout << "| " << left << setw(12) << "phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << "" << left << "\n\t__________________________________________________________________";
        cout << "____________________________________\n";

        if (Vusers.size() == 0)
        {

            cout << "\n\t\t\tNo User Availabl In The System!\n";
        }
        for (clsUser& User : Vusers)
        {
            _PrintUserRecordLine(User);

            cout << endl;
        }
        cout << setw(8) << "" << left << "\n\t__________________________________________________________________";
        cout << "____________________________________\n";

    }
};

