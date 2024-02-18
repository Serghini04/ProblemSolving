#include "first_header.h"

#include <iostream>
#include <ctime>

int main()
{
    int map[3][3];
    cout << "Matrix1:\n";
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cin >> map[i][j];
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if ((i != j && map[i][j] != 0) || (i == j && map[i][j] != 1))
            {
                cout << "Not : Matrix identity\n";
                return (1);
            }
        }
    }
    cout << "YES : Matrix is identity\n";
}
