#include "first_header.h"


int myround(float nb)
{
	int s, res;
	float r;
	s = int(nb);
	r = nb - s;
	res = int(r*10);
	if (res >= 5)
		return (nb + 1);
	else if (res <= -5)
		return (nb - 1);
	else
		return (nb);
}

int myceil(int a)
{
	if (a < 0)
		return (a);
	else
		return (a + 1);
}

int myfloor(float nb)
{
	if (nb < 0)
		return (nb - 1);
	else
		return (nb);
}

int mysqrt(int a)
{
	pow(a, 0.5);
}

int main()
{
	float n;
	cin >> n;
	cout << myfloor(n)<< "\n";
}