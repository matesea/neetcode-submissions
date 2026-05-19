class Solution {
public:
    int countSubstrings(string s) {
        int res = s.size();
        for (int i = 0; i < s.size(); ++i) {
            int j = 1;
            while (i - j >= 0 && i + j < s.size() && s[i-j] == s[i+j]) ++j;
            --j;
            res += j;
            if (i+1 >= s.size() || s[i] != s[i+1]) continue;
            j = 1;
            while (i - j >= 0 && i + j + 1 < s.size() && s[i-j] == s[i+j+1]) ++j;
            --j;
            res += j + 1;
        }
        return res;
    }
};
