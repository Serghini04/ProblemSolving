#include "oop.h"
#include "clsPerson.h"
using namespace std;

class	clsBankClient : public clsPerson
{
private:
	enum	enMode{EmptyMode, UpdateMode};
	string	_id;
	string	_pin;
	int		_balance;
	int		_Mode;
	string	Id()
	{
		return (_id);
	}
	string	Pin()
	{
		return (_pin);
	}
	int	Balance()
	{
		return (_balance);
	}
	int	Mode()
	{
		return (_Mode);
	}
	void	SetPin(string pin)
	{
		_pin = pin;
	}
	void	SetBalance(int balance)
	{
		_balance = balance;
	}
	// void	SetMode(int mode)
	// {
	// 	_Mode =  mode;
	// }
	static vector<string> _split(string s, string del)
	{
	    vector<string> res;
	    string word;
	    int pos;
	    while ((pos = s.find(del)) != std::string::npos)
	    {
	        word = s.substr(0, pos);
	        if (word != "")
	            res.push_back(word);
	        s.erase(0, pos + del.length());
	    }
	    if (s != "")
	        res.push_back(s);
	    return (res);
	}
	static clsBankClient _ConvertLineObject(string line)
	{
		vector<string> data;
		data = _split(line, ">>>");
		return (clsBankClient(enMode::UpdateMode, data[1], data[2], data[0], data[4], data[3], stoi(data[5])));
	}
	static clsBankClient _EmptyClientObject()
	{
		return (clsBankClient(enMode::EmptyMode, "", "", "", "", "", 0));
	}
public:
	clsBankClient(int Mode, string Name, string Email, string id, string Phone, string pin, int balance)
	 : clsPerson(Name, Email, Phone)
	{
		_Mode = Mode;
		_id = id;
		_pin = pin;
		_balance = balance;
	}
	void	Print()
	{
		std::cout << "Client Card :\n";
		std::cout << "----------------------------------\n";
		std::cout << "  Account Number " << ":" << "  "<< _id << "\n";
		std::cout << "  Name           " << ":" << "  "<< Name() << "\n";
		std::cout << "  Email          " << ":" << "  "<< Email() << "\n";
		std::cout << "  Pin Code       " << ":" << "  "<< _pin << "\n";
		std::cout << "  Phone          " << ":" << "  " << Phone() << "\n";
		std::cout << "  balance        " << ":" << "  " << _balance << "\n";
		std::cout << "----------------------------------\n";
	}
	static	clsBankClient Find(string id)
	{
		vector	<clsBankClient> vClients;
		fstream fd;
		fd.open("clients", ios::in);
		if (fd.is_open())
		{
			string  line;
			while (getline(fd, line))
			{
				clsBankClient Client = _ConvertLineObject(line);
				if (Client._id == id)
				{
					fd.close();
					return (Client);
				}
			}
			fd.close();
		}
		return (_EmptyClientObject());
	}
	static	clsBankClient Find(string id, string pin)
	{
		vector	<clsBankClient> vClients;
		fstream fd;
		fd.open("clients", ios::in);
		if (fd.is_open())
		{
			string  line;
			while (getline(fd, line))
			{
				clsBankClient Client = _ConvertLineObject(line);
				if (Client.Id() == id && Client.Pin() == pin)
				{
					fd.close();
					return (Client);
				}
			}
			fd.close();
		}
		return (_EmptyClientObject());
	}
	static bool IsClientExit(clsBankClient Client)
	{;
		return (Client.Mode() == 1);
	}
	// void update_info()
	// {
	// 	string c;
	// 	system("clear");
	// 	cout << "----------------------------------\n";
	// 	cout << setw(5) << "Update Client Info Screen\n";
	// 	cout << "----------------------------------\n";
	// 	cout << "Please enter Account Number?\n";
	// 	cin >> c;
	// 	clsBankClient Client = clsBankClient::Find(c);
	// 	if (clsBankClient::IsClientExit(Client))
	// 	{
	// 		;
	// 		char c;
	// 		cout << "Are you sure you want update this client? (y/n)\n";
	// 		cin >> c;
	// 		if (c == 'n')
	// 			break;
	// 		cout << "Enter Pin Code? ";
	// 		cin >> it->pin;
	// 		cout << "Enter Name? ";
	// 		cin >> it->name;
	// 		cout << "Enter Phone? ";
	// 		cin >> it->phone;
	// 		cout << "Enter Accout balance? ";
	// 		cin >> it->balance;
	// 		cout << "Client update successfully\n";
	// 		break;
	// 	}
	// 	cout << "Press any key to go back to Main Menue? ...\n";
	// 	cin >> c;
	// }
};