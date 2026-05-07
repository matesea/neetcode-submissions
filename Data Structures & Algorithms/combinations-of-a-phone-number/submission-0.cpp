class Solution {
    vector<string> res;
    void rec(string& digits, int i, string& path, unordered_map<char,vector<char>>& um) {
        if (i == digits.size()) {
            res.push_back(path);
            return;
        }
        for (auto& c: um[digits[i]]) {
            path.push_back(c);
            rec(digits, i + 1, path, um);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> um = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };
        if (!digits.size())
            return res;
        string s;
        rec(digits, 0, s, um);
        return res;
    }
};
