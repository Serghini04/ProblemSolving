# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> dic;
        int ans = 0;
        int left = 0;

        // abba
        //   l
        //    r
        for (int right = 0; right < s.length(); ++right) {
            char ch = s[right];
            if (dic.count(ch) && dic[ch] >= left)
                left = dic[ch] + 1;
            dic[ch] = right;
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }

};