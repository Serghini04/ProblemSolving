#include "../l3/first_header.h"

typedef struct s_data
{
	int day;
	int month;
	int year;
}t_data;

typedef struct s_period
{
	t_data start;
	t_data end;
}	t_period;

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

t_data	add_years(int nb, t_data data)
{
	data.year += nb;
	return (data);
}

t_data	add_days(int days, t_data data)
{
	int nb_days_month = number_days_month(data.month, data.year);
	while (days)
	{
		if (data.day == nb_days_month)
		{
			data.month++;
			if (data.month >= 13)
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
		if (data.day <= 0)
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

void print_data(t_data data)
{
	cout << ", " << data.day << "/" << data.month << "/" << data.year << endl;
}

t_data add_month(int months, t_data data)
{
	short	nb_days;
	while (months)
	{
		if (data.month == 12)
		{
			data.month = 1;
			data.year++;
		}
		nb_days = number_days_month(data.month, data.year);
		data = add_days(nb_days, data);
		months--;
	}
	return (data);
}

short	nb_day_of_week(t_data data)
{
	short a, y, m;
	a = (14 - data.month) / 12;
	y = data.year - a;
	m = data.month + (12 * a) - 2;
	// Gregorian:
	// 0:sun, 1: Mon, 2:Tue, ... etc.
	return (data.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool	IsEndOfWeek(t_data data)
{
	return (nb_day_of_week(data) == 0);
}

bool	IsWeekend(t_data data)
{
	int nb = nb_day_of_week(data);
	return (nb == 6 || nb == 0);
}

string print_day_short(t_data data)
{
	string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	return (days[nb_day_of_week(data)]);
}

bool IsBusinessDay(t_data data)
{
	return (!IsEndOfWeek(data));
}

int	DaysUntilTheEndOfWeek(t_data data)
{
	return (7 - nb_day_of_week(data));
}

int DayUntilTheEndOfMonth(t_data data)
{
	int days = number_days_month(data.month, data.year);
	return ((days - data.day) + 1);
}

int	DayUntilTheEndOfYear(t_data data)
{
	int count = number_days_month(data.month, data.year) - data.day; 
	while (data.month < 12)
	{
		count += number_days_month(data.month + 1, data.year);
		data.month++;
	}
	return (count + 1);
}

t_data get_date_end(t_data data,int days_vacation)
{
 	data = add_days(DaysUntilTheEndOfWeek(data), data);
	return (add_days(days_vacation + 8, data));
}



bool IsDate1BeforeDate2(t_data Date1, t_data Date2)
{
	return  (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false); 
}
bool IsDate1EqualDate2(t_data Date1, t_data Date2)
{
	return  (Date1.year == Date2.year) ? ((Date1.month == Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false) : false;
}
bool IsDate1AfterDate2(t_data Date1, t_data Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
} 


int	cmp_two_date(t_data data1, t_data data2)
{
	if (IsDate1AfterDate2(data1, data2))
		return (1);
	else if (IsDate1BeforeDate2(data1, data2))
		return (-1);
	else
		return (0);
}

bool	is_period_overlap(t_period data1, t_period data2)
{
	//cmp_two_date(data2.end, data1.start) == -1 ==> 2.end < 1.start
	if (cmp_two_date(data2.end, data1.start) == -1 || cmp_two_date(data2.start, data1.end) == 1)
		return (false);
	return (true);
}

bool isDateInPeriod(t_data Date, t_period Period)
{
	return !(cmp_two_date(Date, Period.start) == -1 || cmp_two_date(Date, Period.end) == 1); 
}

int	count_peroid_overlap(t_period data1, t_period data2)
{
	if(!is_period_overlap(data1, data2))
		return (0);
	if (isDateInPeriod(data2.start, data1))
		return (cout << "\nha ana\n", data_diff_days(data2.start, data1.end));
	else
		return (cout <<"\nmachi ana\n", data_diff_days(data1.start, data2.end));
}


// int main()
// {
// 	t_data data = get_date();
// 	cout << "Today is " << print_day_short(data);
// 	print_data(data);
// 	cout << "\nIs it End of Week?\n";
// 	if (!IsEndOfWeek(data))
// 		cout << "No it's Not end of week.\n";
// 	else
// 		cout << "Yes it's end of week.\n";
// 	cout << "\nIt's Weekend?\n";
// 	if (IsWeekend(data))
// 		cout << "Yes it's a week end.\n";
// 	else
// 		cout << "No it's not a week end.\n";
// 	cout << "\nIt's Business day?\n";
// 	if (IsBusinessDay(data))
// 		cout << "Yes it's a business day.\n";
// 	else
// 		cout << "No it's Not a business day.\n";
// 	cout << "\nDays unit end of Week : " <<DaysUntilTheEndOfWeek(data)<< " Day(s).\n";
// 	cout << "Days unit end of Month : " <<DayUntilTheEndOfMonth(data)<< " Day(s).\n";
// 	cout << "Days unit end of year : " <<DayUntilTheEndOfYear(data)<< " Day(s).\n";
// 	return 0;
// }


int main()
{
	t_period data1;
	t_period data2;
	cout << "Enter Peroid 1:\n";
	data1.start = read_data();
	data1.end = read_data();
	cout << "\nEnter Peroid 1:\n";
	data2.start = read_data();
	data2.end = read_data();
	cout << "Days : " << count_peroid_overlap(data1, data2) << endl;
}