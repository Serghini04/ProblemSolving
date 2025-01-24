#include "../l3/first_header.h"

string print_nb(size_t	nb)
{
	if(nb == 0)
		return ("");
	else if (nb >= 1 && nb <= 19)
	{
		string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",\
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen",\
		"Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return (arr[nb] + " ");
	}
	else if (nb >= 20 && nb <= 99)
	{
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy"\
						,"Eighty","Ninety"};
		return (arr[nb / 10] + " " + print_nb(nb % 10));
	}
	else if (nb >= 100 && nb <= 999)
		return (print_nb(nb / 100) + "Hundreds " + print_nb(nb % 100));
	else if (nb >= 1000 && nb <= 999999)
		return (print_nb(nb / 1000) + "thousands " + print_nb(nb % 1000));
	else if (nb >= 1000000 && nb <= 999999999)
		return (print_nb(nb / 1000000) + "Millions " + print_nb(nb % 1000000));
	else if (nb >= 1000000000 && nb <= 9999999999)
		return (print_nb(nb / 1000000000) + "Billion " + print_nb(nb % 1000000000));
	return ("number invalid\n");
}

int main()
{
	size_t nb;
	cout << "Enter a Number?\n";
	cin >> nb;
	cout << print_nb(nb);
}