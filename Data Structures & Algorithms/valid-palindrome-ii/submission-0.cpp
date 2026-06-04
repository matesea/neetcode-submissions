class Solution {
    bool check(string& s, int i, int j, int k = 1) {
        while (i < j) {
            if (s[i] != s[j]) {
                if (!k) return false;
                return check(s, i+1, j, k-1) || check(s, i, j-1, k-1);
            }
            ++i, --j;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
       return check(s, 0, s.size()-1);
    }
};