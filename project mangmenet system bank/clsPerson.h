#pragma once
#include"string"
using namespace std;
class clsPerson
{
	

	private:
		string _FirstName;
		string _LastName;
		string _Phone;
		string _Email;
	
	public:
		//constructor for insilization data members inside class;


		clsPerson(string FirstName, string LastName, string Email, string Phone)
		{
		
			_FirstName = FirstName;
			_LastName = LastName;
			_Email = Email;
			_Phone = Phone;

		}
		//set property
		void SetFirstName(string FirstName)
		{
			_FirstName = FirstName;
		}
		//get property;
		string GetFirstName()
		{
			return _FirstName;
		}
		_declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;
		//set property
		void SetLastName(string LastName)
		{
			_LastName = LastName;
		}
		//Get property;
		string GetLastName()
		{
			return _LastName; 
		}
		_declspec(property(get = GetLastName, put = SetLastName))string LastName;
		//set property
		void SetEmail(string Email)
		{
			_Email = Email;

		}
		//Get property
		string GetEmail()
		{
			return _Email;
		}
		_declspec(property(get = GetEmail, put = SetEmail))string Email;
		//set property
		void SetPhone(string Phone)
		{
			_Phone = Phone;
		}
		//Get property
		string GetPhone()
		{
			return _Phone;
		}
		_declspec(property(get = GetPhone, put = SetPhone))string Phone;
		//Get property
		string FullName()
		{
			return _FirstName + " " + _LastName;
		}
};

