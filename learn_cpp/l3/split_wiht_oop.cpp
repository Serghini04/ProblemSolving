#include "first_header.h"

vector<string> split(string s, char del)
{
    vector<string> res;
    string word;
    int pos;
    while ((pos = s.find(del)) != std::string::npos)
    {
        word = s.substr(0, pos);
        if (word != "")
            res.push_back(word);
        s.erase(0, pos + 1);
    }
    if (s != "")
        res.push_back(s);
    return (res);
}

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);
    vector<string> res = split(s, ' ');
    for (string &word : res) {
        cout << word << endl;
    }
    return 0;
}
