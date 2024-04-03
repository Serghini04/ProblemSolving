#include "first_header.h"

//this is very easy  ....
void	get_next_line(string path)
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

int main()
{
	get_next_line("first_header.h");
	return 0;
}