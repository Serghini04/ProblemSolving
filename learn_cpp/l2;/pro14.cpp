#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;


int main()
{
	int a = 'A';
	int in;
	cin >> in;
	a +=in - 1;
	int i = 0;
	while (i < in)
	{
		int j = i;
		while (j < in)
		{
			cout << char(a);
			j++;
		}
		cout << '\n';
		a--;
		i++;
	}
}