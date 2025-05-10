# include <iostream>
# include <string>

using namespace std;

class Solution {
    private:
        string ans;
        int maxAns = 0;

        void    checkPalindrome(string s, int start, int end) {
            while (start >= 0 && end < (int)s.size() && s[start] == s[end]) {
                start--;
                end++;
            }
            if (end - start - 1 > maxAns) {
                maxAns = end - start - 1;
                ans = s.substr(start + 1, maxAns);
            }
        }
    public:
        string longestPalindrome(string s) {
            if (s.empty())
                return s;
            maxAns = 1;
            ans = s.substr(0, 1);
            for (int i = 0; i < (int)s.size(); i++) {
                checkPalindrome(s, i, i);
                checkPalindrome(s, i, i + 1);
            }
            return ans;
        }
};
