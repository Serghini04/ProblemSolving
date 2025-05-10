# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
void rotate(std::vector<int>& nums, int k) {
    int s = nums.size();
    k = k % s;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}
};