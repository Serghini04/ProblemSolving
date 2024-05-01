#include "oop.h"

void update_info()
{
	string c = "";
	system("clear");
	cout << "----------------------------------\n";
	cout << setw(5) << "Update Client Info Screen\n";
	cout << "----------------------------------\n";
	while (!clsBankClient::IsClientExit(c))
	{
		cout << "Please enter Account Number?\n";
		cin >> c;
	}
	clsBankClient Client = clsBankClient::Find(c);
	Client.Print();
	cout << "Are you sure you want update this client? (y/n)\n";
	cin >> c;
	if (c == "n")
		return ;
	string input;
	cout << "Enter Pin Code? \n";
	cin >> input;
	Client.SetPin(input);
	cout << "Enter Name? \n";
	getline(cin, input);
	Client.SetName(input);
	cout << "Enter Email? \n";
	cin >> input;
	Client.SetEmail(input);
	cout << "Enter Phone? \n";
	cin >> input;
	Client.SetPhone(input);
	cout << "Enter Accout balance? \n";
	int b;
	cin >> b;
	Client.SetBalance(b);
	cout << "Client update successfully\n";
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> c;
}

int main()
{
	clsBankClient Client1 = clsBankClient::Find("A000");
	update_info();
	Client1.Print();
}