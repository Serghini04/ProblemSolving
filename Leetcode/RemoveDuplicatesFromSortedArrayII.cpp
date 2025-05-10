# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int v = 0;
		int j = 1;
		int s = nums.size();
		for (int i = 1; i < s; i++)
		{
			if (nums[i] == nums[i - 1])
				v++;
			else
				v = 0;
			if (v < 2)
			{
				nums[j] = nums[i];
				j++;
			}
		}
		return (j);
    }
};