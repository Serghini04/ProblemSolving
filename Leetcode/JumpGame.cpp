# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int	size = nums.size() - 1, max1 = 0;
        for (int i = 0; i < size; i++)
        {
            max1 = max(--max1, nums[i]);
            if (max1 <= 0)
                return 0;
        }
        return 1;
    }
};