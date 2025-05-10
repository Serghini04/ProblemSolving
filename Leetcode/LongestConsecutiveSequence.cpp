# include <iostream>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.empty())
            return 0;
        int ans = 1, start = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (start + 1 == nums[i]){
                count++;
                start++;
            }
            else if (start != nums[i]){
                ans = max(count, ans);
                count = 1;
                start = nums[i];
            }
        }
        ans = max(count, ans);
        return ans;
    }
};