class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (auto& c: s) {
            if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9') {
                if ('A' <= c && c <= 'Z')
                    t.push_back(tolower(c));
                else t.push_back(c);
            }
        }
        for (int i = 0; 2*i < t.size(); ++i) {
            if (t[i] != t[t.size() - 1 - i])
                return false;
        }
        return true;
    }
};
