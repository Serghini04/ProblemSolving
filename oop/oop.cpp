#include "oop.h"

int main()
{
	clsBankClient Client1 = clsBankClient::Find("A000");
	Client1.Print();
}