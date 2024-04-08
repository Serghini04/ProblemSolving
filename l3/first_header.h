#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

// auto is type variable ..
//g++ -std=c++11 testheder.cpp
//int randNum = rand() % (To - From + 1) + From;
using namespace std;
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define RESET   "\033[0m"


namespace mylib
{
	void test()
	{
		cout << BOLDRED <<  "hi me .......\n" << RESET;
	}
	int sum(int n1, int n2)
	{
		return (n1 + n2);
	}
	int checker_integer_nbr()
	{
		int i = 0;
		cin >> i;
		while (cin.fail())
		{
			cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout <<  BOLDRED<< "invalid number, enter a valid one: \n" << RESET;
			cin >> i;
		}
		return(i);
	}
	///learn default parameters ...
	int sum_def_para(int a, int b, int c = 0, int d = 0)
	{
		return (a + b + c + d);
	}
	void	readfile(string path)
	{
		fstream myfile;
		myfile.open(path, ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
				cout << line << endl;
			myfile.close();
		}
	}
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
}