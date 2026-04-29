class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int i = 0; 
       int res = 0;
       vector<int> count(256, 0);
       for (int j = 0; j < s.size(); ++j) {
        count[s[j]]++;
        while (count[s[j]] > 1) {
            count[s[i++]]--;
        }
        res = max(res, j - i + 1);
       }
       return res;
    }
};
