#pragma once
#include <iomanip>
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email    : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone    : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode   : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\Enter Account Balance : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card : ";
		cout << "\n_______________________________";
		cout << "\nFirstName   : "<< Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name    : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc.Number  : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.AccountBalance;
		cout << "\n_____________________________________\n";
	}
public:
	static void ShowAddNewClientScreen()
	{
		_DrawScreenHeader("\t  Add New Client Screen ");

		string AccountNumber = "";
		cout << "\nPlease enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is Already used, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty ";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved beacuse account number is used !\n";
			break;
		}
		}
	}

};

