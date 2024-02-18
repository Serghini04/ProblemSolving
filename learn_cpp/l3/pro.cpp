#include "first_header.h"

typedef struct s_client
{
	string id;
	string name;
	int		pin;
	string	phone;
	int		balance;
}t_client;

int start()
{
	int nb;
	printf("=============================\n");
	printf("	Main Menue Screen\n");
	printf("=============================\n");
	printf("[1] Show Client List.\n");
	printf("[2] Add New Client.\n");
	printf("[3] Delete Client.\n");
	printf("[4] Update Client Info.\n");
	printf("[5] Find Client.\n");
	printf("[6] Exit.\n");
	printf("=============================\n");
	printf("Choose whatt do you want to do? [1 to 6]?\n");
	cin >> nb;
	if (nb >= 1 && nb <= 6)
		return (nb);
	return (-1);
}

void show_clients(t_client *data, int pos)
{
	int i = 0;
	system("clean");
	int c;
	do{
		cout << "---------------------------------------------------------------------------\n";
		cout << "| Accout Number | Pin Code | Client Name	  | Phone	 | Blance\n";
		cout << "---------------------------------------------------------------------------\n";
		while (i <= pos)
		{
			cout << "|" << data[i].id << data[i].pin << data[i].phone << data[i].balance;
			i++;
		}
		cin >> c;
	}while (c != 'x');
}

void	add_client(t_client *data, int *nbr_client)
{
	int c;
	do
	{
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
		cout << "Client Added Successfully, do you want to add more clients? (y/n)";
		cin >> c;
	} while (c != 'y');
}

int main()
{
	int nb;
	t_client *data;
	data = new t_client;
	int nbr_cline = 0;
	do
	{
		nb = start();
		if (nb == 1)
			show_clients(data, nbr_cline);
		else if (nb == 2)
			add_client(data, &nbr_cline);
	} while (nb != 6);
}