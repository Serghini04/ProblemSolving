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
    while (!(cin >> nb) || nb < 1 || nb > 6)
    {
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number between 1 and 6: ";
            cin.clear();  // Clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
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
			i++;
    } while (nb != 6);
}