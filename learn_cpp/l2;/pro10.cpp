#include <string.h>
#include <iostream>

using namespace std;

int ft_len(int nb)
{
	int i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void checker_nbr(int nb)
{
	int len = ft_len(nb);
	int t[len];
	int i = 0;
	while (i < len)
	{
		t[i] = nb % 10;
		i++;
		nb /= 10;
	}
	i = 0;
	len--;
	while (i < len / 2)
	{
		if (t[i] != t[len - i])
		{
			cout << "No, this number is not Palindrome ...\n";
			return ;
		}
		i++;
	}
	cout << "Yes, this number is Palindrome ...\n";
}
int main()
{
	int n1;
	int n2;
	cin >> n1;
	cin >> n2;
	checker_nbr(n1);
	checker_nbr(n2);
}