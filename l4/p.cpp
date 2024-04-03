#include "../l3/first_header.h"


typedef struct s_data
{
	int day;
	int month;
	int year;
}t_data;

int	is_leap_year(int nb)
{
	return ((nb % 4 == 0 && (nb % 100 != 0 || nb % 400 == 0)));
}

int number_days_month(int month, int year)
{
	int _month[7] ={1, 3, 5, 7, 8, 10, 12};
	if (month == 2)
		return (is_leap_year(year) ? 29 : 28);
	for (int i = 0; i < 7; i++)
	{
		if (_month[i] == month)
			return (31);
	}
	return (30);
}

int get_day_from_year(t_data data)
{
	int days = 0;
	for (int i = 0; i <= data.month - 1; i++)
		days += number_days_month(i, data.year);
	return (days + data.day);
}

t_data add_day(t_data data, int nb)
{
	int max_day = nb + get_day_from_year(data);
	int month = 0;
	data.month = 1;
	while (1)
	{
		month = number_days_month(data.month, data.year);
		if (max_day > month)
		{
			max_day -= month;
			data.month++;
			if (data.month > 12)
			{
				data.month = 1;
				data.year++;
			}
		}
		else
		{
			data.day = max_day;
			break;
		}
	}
	return (data);
}

int main()
{
	t_data data;
	int nb;
	cout << "Enter a Day?\n";
	cin >> data.day;
	cout << "Enter a Month?\n";
	cin >> data.month;
	cout << "Enter a Year?\n";
	cin >> data.year;
	cout << "How many days to add?\n";
	cin >> nb;
	data = add_day(data, nb);
	cout << "Date after adding [" << nb << "] day is :"<< data.day <<"/" <<data.month << "/" << data.year;
}