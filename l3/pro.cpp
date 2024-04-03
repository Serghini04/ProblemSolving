#include "first_header.h"

typedef struct s_client
{
	string	id;
	string	name;
	string	pin;
	string	phone;
	int		balance;
}t_client;

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
    printf("[7] Exit.\n");
    printf("=============================\n");
	cout << "Choose what do you want to do ?[1 to 7]?";
	do
	{
		cin >> nb;
	} while (!(nb >= 1 && nb <= 7));

    return nb;
}

void show_clients(const vector<t_client>& data)
{
    string c;
    system("clear");
    cout << setw(40) << "Client List (" << data.size() << ") Client(s).\n";
    cout << "---------------------------------------------------------------------------\n";
    cout << "| Account Number | Pin Code | Client Name       | Phone          | Balance\n";
    cout << "---------------------------------------------------------------------------\n";
    for (const t_client& info : data)
    {
        cout << "|" << setw(15) << info.id << "|" << setw(10) << info.pin << "|" << setw(22) << info.name << "|" << setw(14) << info.phone << "|" << setw(8) << info.balance << "\n";
    }
    cout << "Press any Key to go back to Main Menu ....\n";
    cin >> c;
}

void	add_client(vector<t_client>& data)
{
	string c;
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
		getline(cin, info.name);
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
void	delete_client(vector<t_client>& data)
{
	string c;
	system("clear");
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
	string n;
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> n;
}

void update_info(vector<t_client>& data)
{
	string input;
	system("clear");
	cout << "----------------------------------\n";
	cout << setw(5) << "Update Client Info Screen\n";
	cout << "----------------------------------\n";
	cout << "Please enter Account Number?\n";
	cin >> input;
	for(auto it = data.begin(); it != data.end(); ++it)
	{
		if (input == it->id)
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
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> input;
}

void find_client(vector<t_client>& data)
{
	int i = 0;
	cout << "---------------------------------\n";
	cout << setw(40) << "Find Client Screen\n";
	cout << "---------------------------------\n";
	cout << "Please enter Account number?\n";
	string input;
	cin >> input;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		if (input == it->id)
		{
			info_client(*it);
			return ;
		}
	}
	cout << "Clinet not found ...\n";
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> input;
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
void	deposit(vector<t_client> &data)
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
				update_info(data);
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
void withdraw(vector<t_client> &data)
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
				update_info(data);
			}
			return ;
		}
	}
	cout << "Clinet not found ...\n";
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> input;
}

void transaction(vector<t_client>& data)
{
    int nb;

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
            deposit(data);
		else if (nb == 2)
			withdraw(data);
		else if (nb == 3)
			total_balances(data);
    } while (nb != 4);
}

int main()
{
	char	nb;
	vector<t_client> data;
	read_form_file(data);
	int nbr_cline = 0;
    do
    {
        nb = start();
        if (nb == 1)
            show_clients(data);
        else if (nb == 2)
            add_client(data);
		else if (nb == 3)
			delete_client(data);
		else if (nb == 4)
			update_info(data);
		else if (nb == 5)
			find_client(data);
		else if (nb == 6)
			transaction(data);
    } while (nb != 7);
	system("clear");
	save_update(data);
	cout << "=================================\n";
	cout << setw(24) << ">>> end ...\n";
	cout << "=================================\n";
}