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
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (is_leap_year(year) ? 29 : 28) : days[month - 1];
}

int get_day_from_year(t_data data)
{
	int days = 0;
	for (int i = 1; i < data.month; i++)
		days += number_days_month(i, data.year);
	return (days);
}
int all_days(t_data data)
{
	int count = 0;
	while (data.year)
	{
		count += get_day_from_year(data);
		data.year--;
	}
	return (count + data.day);
}
t_data read_data()
{
	t_data data1;
	cout << "----------------\n";
	cout << "Enter a Day ?\n";
	cin >> data1.day;
	cout << "Enter a Month ?\n";
	cin >> data1.month;
	cout << "Enter a Year ?\n";
	cin >> data1.year;
	return (data1);
}
void	if_last_day_in_Month(t_data data)
{
	if (data.day == number_days_month(data.month, data.year))
		cout << "Yes, day is last day in month.\n";
	else
		cout << "No, Day is not last day in month\n";
}

t_data	add_days(int days, t_data data)
{
	int nb_days_month = number_days_month(data.month, data.year);
	while (days)
	{
		if (data.day == nb_days_month)
		{
			data.month++;
			if (data.month == 13)
			{
				data.month = 1;
				data.year++;
			}
			data.day = 0;
			nb_days_month = number_days_month(data.month, data.year);
		}
		else
		{
			data.day++;
			days--;
		}
	}
	return (data);
}

t_data sub_days(int nb, t_data data)
{
	while (nb != 0)
	{
		if (data.day == 0)
		{
			data.month--;
			if (data.month == 0)
			{
				data.month = 12;
				data.year--;
			}
			data.day = number_days_month(data.month, data.year);
		}
		nb--;
		data.day--;
	}
	return (data);
}

bool is_data1_less_data2(t_data Date1, t_data Date2){
	return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? \
	(Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day\
	 < Date2.day : false)) : false);
}

int	data_diff_days(t_data data1, t_data data2)
{
	int days = 0;
	while (is_data1_less_data2(data1, data2))
	{
		days++;
		data1 = add_days(1, data1);
	}
	return (days++);
}

t_data get_date()
{
	t_data data;
	time_t t = time(0);
	tm *now = localtime(&t);
	data.year = now->tm_year + 1900;
	data.month = now->tm_mon + 1;
	data.day = now->tm_mday;
	return (data);
}
int main()
{
	t_data data1 = read_data();
	int days;
	cin >> days;
	data1 = sub_days(days, data1);
	cout << "sub days is : " << data1.day << "/" << data1.month << "/" << data1.year;
}