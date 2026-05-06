class Solution {
    bool isPalindrome(string& s, int i, int j) {
        if (i >= j) return true;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i; --j;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        return partition(s, 0, s.size() - 1);
    }
    vector<vector<string>> partition(string s, int i, int j) {
        vector<vector<string>> res;
        if (i > j)
            return {{}};
        else if (i == j)
            return {{s.substr(i, 1)}};
       for (int k = i; k <= j; ++k) {
        if (isPalindrome(s, i, k)) {
            vector<vector<string>> tmp = partition(s, k+1, j);
            for (const auto& x: tmp) {
                vector<string> t = x;
                t.push_back(s.substr(i, k - i + 1));
                res.push_back(t);
            }
        }
       }
       return res;
    }
};
