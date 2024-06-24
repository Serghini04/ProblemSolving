#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace std;

string ft_encryption(string res)
{
	int i = 0;
	while (res[i])
	{
		res[i] = res[i] + 2;
		i++;
	}
	return (res);
}

string ft_decry(string res)
{
	int i = 0;
	while (res[i])
	{
		res[i] = res[i] - 2;
		i++;
	}
	return (res);
}

int main()
{
	string res;
	getline(cin, res);
	cout << "Text before Encryption : " << res << "\n";
	res = ft_encryption(res);
	cout << "Text after Encryption : " << res << "\n";
	cout << "Text after Decry : " << ft_decry(res);
	return (0);
}