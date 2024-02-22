#include "first_header.h"

int main()
{
    string s1;
    cout << "Enter you sstring ?";
    getline(cin, s1);
    int i = 0;
    cout << s1[i]<< "\n";
    while(s1[i])
    {
        if (s1[i] == ' ' && s1[i + 1])
            cout << s1[i+ 1] << "\n";
        i++;
    }
    return (0);
}