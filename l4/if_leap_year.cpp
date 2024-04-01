#include "../l3/first_header.h"


int	is_leap_year(int nb)
{
	return ((nb % 4 == 0 && (nb % 100 != 0 || nb % 400 == 0)));
}

int main()
{
	int nb;
	cout << "Enter year\n";
	cin >> nb;
	if (is_leap_year(nb))
		return (cout << "Leap Year\n", 0);
	else
		return (cout << "Not Leap Year\n", 0);
}