# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int c = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++)
        {
            if (i < citations[i])
                c++;
            else
                return c;
        }
        return (c);
    }
};