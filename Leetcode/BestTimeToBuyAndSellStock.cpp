# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices)
        {
            int res = 0, buy = prices[0], size = prices.size();
            for (int i = 1; i < size; i++)
            {
                if (buy > prices[i])
                    buy = prices[i];
                else
                    res = max(res, prices[i] - buy);
            }
            return (res);
        }
    };