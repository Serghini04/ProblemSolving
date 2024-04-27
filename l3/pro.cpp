#include "first_header.h"

typedef struct s_client
{
	string	id;
	string	name;
	string	pin;
	string	phone;
	int		balance;
}t_client;

typedef struct s_user
{
	string	user;
	string	pass;
	int		per;
}	t_user;

int start()
{
    int nb;
	system("clear");
    printf("=============================\n");
    printf("    Main Menu Screen\n");
    printf("=============================\n");
    printf("[1] Show Client List.\n");
    printf("[2] Add New Client.\n");
    printf("[3] Delete Client.\n");
    printf("[4] Update Client Info.\n");
    printf("[5] Find Client.\n");
	printf("[6] Transactions.\n");
    printf("[7] Manage Users.\n");
	printf("[8] logout.\n");
    printf("=============================\n");
	cout << "Choose what do you want to do ?[1 to 8]?";
	do
	{
		cin >> nb;
	} while (!(nb >= 1 && nb <= 8));
    return nb;
}

void access_denied()
{
	cout << "==============================\n";
	cout << "Access Denied,\n";
	cout << "You dont have Permission to do this,\n";
	cout << "Please conact your Admin.\n";
	cout << "==============================\n";
}

void show_clients(const vector<t_client>& data, t_user input)
{
    system("clear");
	if ((input.per & 1) != 1)
		access_denied();
	else
	{
		cout << setw(40) << "Client List (" << data.size() << ") Client(s).\n";
		cout << "---------------------------------------------------------------------------\n";
		cout << "| Account Number | Pin Code | Client Name       | Phone          | Balance\n";
		cout << "---------------------------------------------------------------------------\n";
		for (const t_client& info : data)
		{
			cout << "|" << setw(15) << info.id << "|" << setw(10) << info.pin << "|" << setw(22) << info.name << "|" << setw(14) << info.phone << "|" << setw(8) << info.balance << "\n";
		}
	}
    cout << "Press any Key to go back to Main Menu ....\n";
	cin.ignore();
}

void	add_client(vector<t_client>& data, t_user &input)
{
	string c;
	system ("clear");
	if ((input.per & 2) != 2)
		access_denied();
	else
	{
		while (1)
		{
			t_client info;
			system ("clear");
			cout << "--------------------------------------------\n";
			cout << "	Add New Clients Screen\n";
			cout << "--------------------------------------------\n";
			cout << "Adding New Client:\n";
			cout << "Enter Account Number? ";
			cin >> info.id;
			cout << "Enter Pin Code? ";
			cin >> info.pin;
			cout << "Enter Name? ";
			cin >> info.name;
			cout << "Enter Phone? ";
			cin >> info.phone;
			cout << "Enter Accout balance? ";
			cin >> info.balance;
			cout << "Client Added Successfully, do you want to add more clients? (y/n)\n";
			data.push_back(info);
			cin >> c;
			if (c != "y")
				break;
		}
	}
	cout << "Press any key to go back to Main Menue ...\n";
	cin >> c;
}
void info_client(t_client& data)
{
	cout << "The following are the client delaits :\n";
	cout << "--------------------------------------------\n";
	cout << "Account Number " << ": " <<setw(4) << data.id << "\n";
	cout << "Pin Code   " << ":" <<setw(7) << data.pin << "\n";
	cout << "Name   " << ":" <<setw(10)  << data.name << "\n";
	cout << "Phone  " << ":" <<setw(9)  << data.phone << "\n";
	cout << "Account balance" << ":" <<setw(4)  << data.balance << "\n";
	cout << "--------------------------------------------\n";
}
void	delete_client(vector<t_client>& data, t_user &input)
{
	string c;
	system("clear");
	if ((input.per & 4) != 4)
		access_denied();
	else
	{
		cout << "----------------------------------\n";
		cout << setw(5) << "Delete Client Screen\n";
		cout << "----------------------------------\n";
		cout << "Please enter Account Number\n";
		cin >> c;
		int v = 0;
		string input;
		for (auto it = data.begin(); it != data.end(); ++it)
		{
			if (it->id == c)
			{
				info_client(*it);
				cout << "Are you sure you want delete this client? (y/n)\n";
				v = 1;
				cin >> input;
				if (input != "y")
					break;
				data.erase(it);
				break ;
			}
		}
		if (v == 0)
			cout << "Client with Account Number (" << c << ") is Not Found!\n";

	}
	string n;
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> n;
}


void update_info(vector<t_client>& data, t_user &input)
{
	string c;
	system("clear");
	if ((input.per & 8) != 8)
		access_denied();
	else
	{
		cout << "----------------------------------\n";
		cout << setw(5) << "Update Client Info Screen\n";
		cout << "----------------------------------\n";
		cout << "Please enter Account Number?\n";
		cin >> c;
		for(auto it = data.begin(); it != data.end(); ++it)
		{
			if (c == it->id)
			{
				info_client(*it);
				char c;
				cout << "Are you sure you want update this client? (y/n)\n";
				cin >> c;
				if (c == 'n')
					break;
				cout << "Enter Pin Code? ";
				cin >> it->pin;
				cout << "Enter Name? ";
				cin >> it->name;
				cout << "Enter Phone? ";
				cin >> it->phone;
				cout << "Enter Accout balance? ";
				cin >> it->balance;
				cout << "Client update successfully\n";
				break;
			}
		}
	}
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> c;
}

void find_client(vector<t_client>& data, t_user &input)
{
	int i = 0;
	string c;
	system ("clear");
	if ((input.per & 16) != 16)
		access_denied();
	else
	{
		cout << "---------------------------------\n";
		cout << setw(40) << "Find Client Screen\n";
		cout << "---------------------------------\n";
		cout << "Please enter Account number?\n";
		cin >> c;
		for (auto it = data.begin(); it != data.end(); ++it)
		{
			if (c == it->id)
			{
				info_client(*it);
				return ;
			}
		}
		cout << "Clinet not found ...\n";
	}
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> c;
}

vector<string> split(string s, string del)
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

void read_form_file(vector<t_client>& data)
{
	fstream fd;
	string line;
	vector<string> info;
	t_client fill;
	fd.open("save_data.txt", ios::in | ios::out);
	if (!fd.is_open()) {
        cout << "Error opening file!" << endl;
		exit(1);
	}
	if (fd.is_open())
	{
		while (getline(fd, line))
		{
			info = split(line, ">>>");
			fill.id = info[0];
			fill.name = info[1];
			fill.pin = info[2];
			fill.phone = info[3];
			fill.balance = stoi(info[4]);
			data.push_back(fill);
		}
		fd.close();
	}
}
string str_join(t_client& data)
{
	string line;
	line = data.id + ">>>";
	line = line + data.name + ">>>";
	line = line + data.pin + ">>>";
	line = line + data.phone + ">>>";
	line = line + to_string(data.balance);
	return (line);
}

void save_update(vector<t_client>& data)
{
	string line;
	fstream fd;
	fd.open("save_data.txt", ios::out);
	if (!fd.is_open())
	{
		perror("you have error in open a file ...\n");
		exit(1);
	}
	for (t_client& info : data)
	{
		line = str_join(info);
		fd << line << endl;
	}
	fd.close();
}
void	deposit(vector<t_client> &data, t_user user)
{
	string	input;
	int		nb;
	string	conf;
	system("clear");
	cout << "------------------------------\n";
	cout << "	Deposit Screen\n";
	cout << "------------------------------\n";
	cout << "Please enter Account Number?\n";
	cin >> input;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		if (input == it->id)
		{
			info_client(*it);
			cout << "Please enter deposit amount?\n";
			cin >> nb;
			cout << "Are you sure you want perfrom this transaction? (y/n)\n";
			cin >> conf;
			if (conf == "y")
			{
				it->balance	+= nb;
				update_info(data, user);
			}
			return ;
		}
	}
	cout << "Clinet not found ...\n";
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> input;
}
void	total_balances(vector<t_client> &data)
{
	system ("clear");
	int sum = 0;
	cout <<	"	Balances List (" << data.size() << ") Client(s).\n";
	cout << "--------------------------------------------------\n";
	cout << "|  Account Number |  Client Name  |  Balance\n";
	cout << "--------------------------------------------------\n";
	for (auto it = data.begin(); it != data.end(); it++)
	{
		cout << "|" << setw(4) << it->id << setw(10)  << "|" << setw(10) << it->name << setw(6) << "|" << setw(10) << it->balance << endl;
		sum += it->balance;
	}
	cout << "--------------------------------------------------\n";
	cout << "			Total Balances = " << sum << endl;
	cout << "Press any key to go back to Transactions Menue ..." << endl;
	string in;
	cin >> in;
}
void withdraw(vector<t_client> &data, t_user &user)
{
	string	input;
	int		nb;
	string	conf;
	system("clear");
	cout << "------------------------------\n";
	cout << "	Withdraw Screen\n";
	cout << "------------------------------\n";
	cout << "Please enter Account Number?\n";
	cin >> input;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		if (input == it->id)
		{
			info_client(*it);
			do{
				cout << "Please enter withdraw amount?\n";
				cin >> nb;
				if (nb > it->balance)
					cout << "Amount Exceeds the balance, you can withdraw up to :" << it->balance << endl;
				else
					break;
			} while (1);
			cout << "Are you sure you want perfrom this transaction? (y/n)\n";
			cin >> conf;
			if (conf == "y")
			{
				it->balance	-= nb;
				update_info(data, user);
			}
			return ;
		}
	}
	cout << "Clinet not found ...\n";
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> input;
}

void transaction(vector<t_client>& data, t_user input)
{
    int nb;
	string c;

	if ((input.per & 32) != 32)
	{
		system("clear");
		access_denied();
		cout << "Press any key to go back to Main Menue ...\n";
		cin >> c;
	}
	else
	{
		do {
			system("clear");
			cout << "====================================\n";
			cout << "    Transactions Menue Screen\n";
			cout << "====================================\n";
			cout << "[1] Deposit.\n";
			cout << "[2] Withdraw.\n";
			cout << "[3] Total Balances.\n";
			cout << "[4] Main Menue.\n";
			cout << "====================================\n";
			cout << "Choose what do you want to do? [1 to 4]?\n";
			cin >> nb;
			// Check if cin failed
			if (cin.fail()) {
				cin.clear(); // clear the error state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the bad input
				continue; // skip the rest of the loop
			}
			if (nb == 1)
				deposit(data, input);
			else if (nb == 2)
				withdraw(data, input);
			else if (nb == 3)
				total_balances(data);
		} while (nb != 4);
	}
}

void	read_file(vector<t_user> &user)
{
	fstream fd;
	string line;
	vector<string> info;
	t_user fill;
	fd.open("Users.txt", ios::in | ios::out);
	if (!fd.is_open()) {
        cout << "Error opening file!" << endl;
		exit(1);
	}
	if (fd.is_open())
	{
		while (getline(fd, line))
		{
			info = split(line, ">>>");
			fill.user = info[0];
			fill.pass = info[1];
			fill.per = stoi(info[2]);
			user.push_back(fill);
		}
		fd.close();
	}
}

bool	find_user(t_user &input, vector<t_user> &data)
{
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if (it->user == input.user && it->pass == input.pass)
		{
			input.per = it->per;
			return (true);
		}
	}
	return (false);
}

t_user	login_part(vector<t_user> &data)
{
	int v = 1;
	t_user input;
	do
	{
		system("clear");
		cout << "==============================\n";
		cout << "	Login Screeen\n";
		cout << "==============================\n";
		if (!v)
			cout << "Invlaid Username/Password!\n";
		cout << "Enter Username ? ";
		cin >> input.user;
		cout << "Enter Password ? ";
		cin >> input.pass;
		v = 0;
	} while (!find_user(input, data));
	return (input);
}

void	show_users(vector<t_user> &data)
{
	system("clear");
	cout << "	Users List (1) User(s).\n";
	cout << "============================================\n";
	cout << "| User Name" << "   " << "| Password" << "    " << "| Permissions\n";
	cout << "============================================\n";
	for (auto it = data.begin(); it != data.end(); it++)
	{
		cout << "|  " << it->user << "      |	" << it->pass << "	    |    " << it->per << endl;
	}
	cout << "============================================\n";
	string nb;
	cout << "Press any key to go back to Manage Users Menue ...\n";
	cin >> nb;
}

bool	check_double(string user, vector<t_user> &data)
{
	for (auto it = data.begin(); it != data.end(); it++)
	{
		if (user == it->user)
		{
			cout << "User with [" << user << "] already exists, ";
			return (true);
		}
	}
	return (false);
}

void add_per(t_user &data, int per)
{
	string c;
	cin >> c;
	if (c == "y")
		data.per += per;
}

void	update_file_users(vector<t_user> &data)
{
	string line;
	fstream fd;
	fd.open("Users.txt", ios::out);
	if (!fd.is_open())
	{
		perror("you have error in open a file ...\n");
		exit(1);
	}
	for (t_user& info : data)
	{
		line = info.user + ">>>";
		line += info.pass + ">>>";
		line += to_string(info.per);
		fd << line << endl;
	}
	fd.close();
}

void	add_user(vector<t_user> &data)
{
	t_user user;
	string c;
	do
	{
		user.per = 0;
		system ("clear");
		cout << "=============================\n";
		cout << "	Add New User Screen\n";
		cout << "=============================\n";
		cout << "Adding New User:\n";
		do{
			cout << "Enter Username ? ";
			cin >> user.user;
		} while (check_double(user.user, data));
		cout << "Enter Password ? ";
		cin >> user.pass;
		cout << "Do you want to give full access ? (y/n)";
		cin >> c;
		if (c == "y")
			user.per = -1;
		else
		{
			cout << "Do you want to access to :\n";
			cout << "show Client List ? (y/n) ";
			add_per(user, 1);
			cout << "Add New Client ? (y/n) ";
			add_per(user, 2);
			cout << "Delete Client ? (y/n) ";
			add_per(user, 4);
			cout << "Update Client ? (y/n) ";
			add_per(user, 8);
			cout << "Find Client ? (y/n) ";
			add_per(user, 16);
			cout << "Transaction ? (y/n) ";
			add_per(user, 32);
			cout << "Manage Users ? (y/n) ";
			add_per(user, 64);
		}
		cout << "User added Successfully, do you to add more Users? (y/n) ";
		data.push_back(user);
		update_file_users(data);
		cin >> c;
	}	while (c == "y");
}
void info_user(t_user &data)
{
	cout << "The following are the User delaits :\n";
	cout << "--------------------------------------------\n";
	cout << "Username	" << ": " <<setw(4) << data.user << "\n";
	cout << "Password  " << ":" <<setw(7) << data.pass << "\n";
	cout << "Permissions " << ":" <<setw(10)  << data.per << "\n";
	cout << "--------------------------------------------\n";
}

void delete_user(vector<t_user> &data)
{
	string c;
	system("clear");
	cout << "----------------------------------\n";
	cout << setw(5) << "Delete Client Screen\n";
	cout << "----------------------------------\n";
	cout << "Please enter Username?\n";
	cin >> c;
	int v = 0;
	string input;
	if (c != "Admin")
		cout << "You cannot Delete this User.\n";
	else
	{
		for (auto it = data.begin(); it != data.end(); ++it)
		{
			if (it->user == c)
			{
				info_user(*it);
				cout << "\nAre you sure you want delete this user? (y/n)\n";
				v = 1;
				cin >> input;
				if (input != "y")
					cout << "User Deleted Successfuly .\n";
				else
					data.erase(it);
				break ;
			}
		}
		if (v == 0)
			cout << "User (" << c << ") is Not Found!\n";
	}
	string n;
	cout << "Press any key to go back to Manage Users Menue Screen ...\n";
	cin >> n;
}

void update_users(vector<t_user> &data)
{
	string input;
	system("clear");
	cout << "----------------------------------\n";
	cout << setw(5) << "Update Users Screen\n";
	cout << "----------------------------------\n";
	cout << "Please enter Username?\n";
	cin >> input;
	for(auto it = data.begin(); it != data.end(); ++it)
	{
		if (input == it->user)
		{
			info_user(*it);
			char c;
			cout << "Are you sure you want update this user? (y/n)\n";
			cin >> c;
			if (c == 'n')
				break;
			cout << "Enter Password ? ";
			cin >> it->pass;
						cout << "Do you want to access to :\n";
			cout << "show Client List ? (y/n) ";
			add_per(*it, 1);
			cout << "Add New Client ? (y/n) ";
			add_per(*it, 2);
			cout << "Delete Client ? (y/n) ";
			add_per(*it, 4);
			cout << "Update Client ? (y/n) ";
			add_per(*it, 8);
			cout << "Find Client ? (y/n) ";
			add_per(*it, 16);
			cout << "Transaction ? (y/n) ";
			add_per(*it, 32);
			cout << "Manage Users ? (y/n) ";
			add_per(*it, 64);
			cout << "User Update Successfully .\n";
			break;
		}
	}
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> input;
}

void	manage_users(vector<t_user> &data, t_user &input)
{
	int nb;
	string c;
	if ((input.per & 64) != 64)
	{
		system("clear");
		access_denied();
		cout << "Press any key to go back to Main Menue? ...\n";
		cin >> c;
	}
	else
	{
		do{
			system("clear");
			cout << "==================================\n";
			cout << "	Manage Users Menue Screen\n";
			cout << "==================================\n";
			cout << "[1] List Users.\n";
			cout << "[2] Add New User.\n";
			cout << "[3] Delete User.\n";
			cout << "[4] Update User.\n";
			cout << "[5] Main Menue.\n";
			cout << "==================================\n";
			cout << "Choose what do you want to do? [1 to 6]?";
			while(!(cin >> nb))
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a number: ";
			}
			if (nb == 1)
				show_users(data);
			else if (nb == 2)
				add_user(data);
			else if (nb == 3)
				delete_user(data);
			else if (nb == 4)
				update_users(data);
		} while (nb != 5);
	}
}


int main()
{
	char	nb;
	t_user	input;
	vector<t_client> data;
	vector<t_user>	users;
	read_form_file(data);
	read_file(users);
	int nbr_cline = 0;
	input = login_part(users);
    do
    {
        nb = start();
        if (nb == 1)
            show_clients(data, input);
        else if (nb == 2)
            add_client(data, input);
		else if (nb == 3)
			delete_client(data, input);
		else if (nb == 4)
			update_info(data, input);
		else if (nb == 5)
			find_client(data, input);
		else if (nb == 6)
			transaction(data, input);
		else if (nb == 7)
			manage_users(users, input);
		else if (nb == 8)
		{
			save_update(data);
			input = login_part(users);
		}
	} while (nb != 9);
	system("clear");
	cout << "=================================\n";
	cout << setw(24) << ">>> end ...\n";
	cout << "=================================\n";
}