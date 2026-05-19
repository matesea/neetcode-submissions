class Solution {
public:
    string longestPalindrome(string s) {
        int resStart = 0, resLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int j = 0;
            while (i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]) ++j;
            --j;
            if (2*j + 1 > resLen) {
                resStart = i-j;
                resLen = 2*j+1;
            }
            if (i+1 >= s.size() || s[i] != s[i+1])
                continue;
            j = 0;
            while (i-j >= 0 && i+j+1 < s.size() && s[i-j] == s[i+j+1]) ++j;
            --j;
            if (2*j+2 > resLen) {
                resStart = i-j;
                resLen = 2*j+2;
            }
        }
        return s.substr(resStart, resLen);
    }
};
