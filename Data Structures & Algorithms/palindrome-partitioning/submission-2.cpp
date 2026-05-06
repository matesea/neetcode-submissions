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
    void rec(string& s, int i, vector<string>& path, vector<vector<string>>& res) {
        if (i >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                rec(s, j + 1, path, res);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> res;
        rec(s, 0, path, res);
        return res;
    }
};
