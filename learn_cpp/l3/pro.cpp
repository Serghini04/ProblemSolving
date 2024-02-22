#include "first_header.h"

typedef struct s_client
{
	string id;
	string name;
	string pin;
	string	phone;
	string		balance;
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
    printf("[6] Exit.\n");
    printf("=============================\n");
	cout << "Choose what do you want to do ?[1 to 6]?";
    while (!(cin >> nb) || nb < 1 || nb > 6)
    {
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number between 1 and 6: ";
            cin.clear();  // Clear the error flag
        //    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
        }
        else
            cout << "Invalid input. Please enter a valid number between 1 and 6: ";
    }
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
    return nb;
}

void show_clients(t_client *data, int pos)
{
	int i = 0;
	char c;
	system ("clear");
	cout << setw(40) << "Client List (" << pos << ") Client(s).\n";
	cout << "---------------------------------------------------------------------------\n";
	cout << "| Accout Number | Pin Code | Client Name	  | Phone	 | Blance\n";
	cout << "---------------------------------------------------------------------------\n";
	while (i < pos)
	{
		cout << "|" <<  setw(15) << data[i].id << "|" <<  setw(10)  << data[i].pin << "|" <<  setw(22) << data[i].name << "|" <<  setw(14) << data[i].phone << "|" <<  setw(8) << data[i].balance << "\n";
		i++;
	}
	cout << "Press any Key to go back to Main Menue ....\n";
	cin >> c;
}

void	add_client(t_client *data, int *nbr_client)
{
	char c;
	while (1)
	{
		system ("clear");
		cout << "--------------------------------------------\n";
		cout << "	Add New Clients Screen\n";
		cout << "--------------------------------------------\n";
		cout << "Adding New Client:\n";
		cout << "Enter Account Number? ";
		cin >> data[*nbr_client].id;
		cout << "Enter Pin Code? ";
		cin >> data[*nbr_client].pin;
		cout << "Enter Name? ";
		cin >> data[*nbr_client].name;
		cout << "Enter Phone? ";
		cin >> data[*nbr_client].phone;
		cout << "Enter Accout balance? ";
		cin >> data[*nbr_client].balance;
		(*nbr_client)++;
		cout << "Client Added Successfully, do you want to add more clients? (y/n)\n";
		cin >> c;
		if (c != 'y')
			break;
	}
}
void info_client(t_client *data, int nb_client)
{
	cout << "The following are the client delaits :\n";
	cout << "Account Number" <<setw(4) << ":" << data[nb_client].id << "\n";
	cout << "Pin Code" <<setw(7) << ":"  << data[nb_client].pin << "\n";
	cout << "Name" <<setw(10) << ":"  << data[nb_client].name << "\n";
	cout << "Phone" <<setw(9) << ":"  << data[nb_client].phone << "\n";
	cout << "Account balance" <<setw(4) << ":"  << data[nb_client].id << "\n";
	cout << "Are you sure you want update this client? (y/n)?\n";
}
void	delete_client(t_client *data, int *nb)
{
	string c;
	system("clear");
	cout << "----------------------------------\n";
	cout << setw(5) << "Delete Client Screen\n";
	cout << "----------------------------------\n";
	cout << "Please enter Account Number\n";
	cin >> c;
	int i = 0;
	int v = 0;
	char input;
	while (i < *nb)
	{
		if (data[i].id == c)
		{
			info_client(data, i);
			cout << "Are you sure you want delete this client? (y/n)\n";
			cin >> input;
			if (input == 'n')
				break;
			while (i < *nb - 1)
			{
				i++;
				data[i] = data[i + 1];
			}
			(*nb)--;
			v = 1;
			break ;
		}
		i++;
	}
	if (v == 0)
		cout << "Client with Account Number (" << c << ") is Not Found!\n";
	string n;
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> n;
}

void update_info(t_client *data, int nbr_client)
{
	string input;
	system("clear");
	cout << "----------------------------------\n";
	cout << setw(5) << "Update Client Info Screen\n";
	cout << "----------------------------------\n";
	cout << "Please enter Account Number?\n";
	cin >> input;
	for(int i = 0; i < nbr_client; i++)
	{
		if (input == data[i].id)
		{
			info_client(data, i);
			char c;
			cout << "Are you sure you want update this client? (y/n)\n";
			cin >> c;
			if (c == 'n')
				break;
			cout << "Enter Pin Code? ";
			cin >> data[i].pin;
			cout << "Enter Name? ";
			cin >> data[i].name;
			cout << "Enter Phone? ";
			cin >> data[i].phone;
			cout << "Enter Accout balance? ";
			cin >> data[i].balance;	
			cout << "Client update successfully\n";
			break;
		}
	}
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> input;
}

void find_client(t_client *data, int nb_client)
{
	int i = 0;
	cout << "---------------------------------\n";
	cout << setw(40) << "Find Client Screen\n";
	cout << "---------------------------------\n";
	cout << "Please enter Account number?\n";
	string input;
	cin >> input;
	while (i < nb_client)
	{
		if (input == data[i].id)
		{
			info_client(data, i);
			return ;
		}
	}
	cout << "Clinet not found ...\n";
	cout << "Press any key to go back to Main Menue? ...\n";
	cin >> input;
}

int main()
{
	char	nb;
	t_client *data;
	data = new t_client[2555];
	int i = 0;
	int nbr_cline = 0;
    do
    {
        nb = start();
        if (nb == 1)
            show_clients(data, nbr_cline);
        else if (nb == 2)
            add_client(data, &nbr_cline);
		else if (nb == 3)
			delete_client(data, &nbr_cline);
		else if (nb == 4)
			update_info(data, nbr_cline);
		else if (nb == 5)
			find_client(data, nbr_cline);
		i++;
    } while (nb != 6);
	system("clear");
	cout << "=================================\n";
	cout << setw(40) << "end ...\n";
	cout << "=================================\n";
}