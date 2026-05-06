class Solution {
    vector<string> res;
    void rec(int left, int right, int n, string& s) {
        if (left == right && left == n) {
            res.push_back(s);
            return;
        }
        if (left > right) {
            s.push_back(')');
            rec(left, right + 1, n, s);
            s.pop_back();
        }
        if (left < n) {
            s.push_back('(');
            rec(left + 1, right, n, s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        rec(0, 0, n, s);
        return res;
    }
};
