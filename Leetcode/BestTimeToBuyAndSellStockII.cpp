# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0, size = prices.size();
        for (int i = 1; i < size; i++)
            res += max(0, prices[i] - prices[i - 1]);
        return (res);
    }
};