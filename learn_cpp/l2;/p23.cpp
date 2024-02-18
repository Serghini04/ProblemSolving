#include <string.h>
#include <iostream>
#include <unistd.h>
//i 
using namespace std;

char rand_nbr()
{
	return (rand() % (90 - 65 + 1) + 65);
}
int main()
{
	srand(time(0));
	int nb = 0;
	cout << "Array Elements: ";
	cin >> nb;
	int i = 0;
	while (i < nb)
	{
		cout << " " << char(rand_nbr());
		i++;
	}
}


int main()
{
	int i = 1;
	int n;
	cin >> n;
	int t[n];
	cout << "Enter array element\n";
	while (i <= n)
	{
		cout << "Element [" << i << "] :";
		cin >> t[i];
		i++;
	}
	int nb;
	cout << "Enter the number ou wnst to check :";
	cin >> nb;
	int count = 0;
	i = 1;
	cout << "Original array :";
	while (i <= n)
	{
		cout <<  " " << t[i];
		if (nb == t[i])
			count++;
		i++;
	}
	cout << "\n" << nb << " is repeated " << count << "time(s)\n";
}