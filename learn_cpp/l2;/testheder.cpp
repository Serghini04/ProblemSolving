#include "first_header.h"

//g++ -std=c++11 testheder.cpp

typedef struct s_lean
{
	string Name;
	float Salary;
} t_lean;

int main()
{
	int s = 5;
	int &n = s;
	cout << n;
}
