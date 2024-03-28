#include <string.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cctype>
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
string check_val(int i)
{
	if (i == 1)
		return ("Stone\n");
	else if (i == 2)
		return ("Paper\n");
	else
		return ("Scissors\n");
}

void checker_winner(int c, int i)
{
	int ai = rand() % (3 - 1 + 1) + 1;
	cout << "_____________Round [" << i << "]____________________\n";
	cout << "Player Choice : " << check_val(c);
	cout << "Computer Choice: " << check_val(ai);
	cout << "Round Winner   : ";
	if (ai == c)
		cout  << BOLDBLUE << "[No Winner]\n" << RESET;
	else if (ai == 1 && c == 2)
		cout << BOLDGREEN <<"[Player]\n"<< RESET;
	else if (ai == 1 && c == 3)
		cout << BOLDRED << "[Computer]\n"<< RESET;
	else if (ai == 2 && c == 1)
		cout << BOLDRED <<"[Computer]\n"<< RESET;
	else if (ai == 2 && c == 3)
		cout << BOLDGREEN <<"[Player]\n"<< RESET;
	else if (ai == 3 && c == 1)
		cout <<BOLDGREEN << "[Player]\n"<< RESET;
	else if (ai == 3 && c == 2)
		cout <<  BOLDRED <<"[Computer]\n"<< RESET;
	cout << "__________________________________________\n";
}

int main()
{
	int i = 1;
	int  c;
	int w = 0;
	int l = 0;
	int n;
	srand(time(0));
	cout << BOLDYELLOW << "How Many Rounds 1 to 10 ?\n" << RESET;
	cin >> n;
	while (i <= n)
	{
		cout << BOLDBLACK << "Round [" << 1 << "] begins :\n";
		cout << "Your Choice: [1]Stone, [2]Paper, [3]Scissors ?" << RESET;
		cin >> c;
		checker_winner(c, i);
		i++;
	}
}