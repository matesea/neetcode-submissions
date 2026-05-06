class Solution {
    unordered_map<int,vector<string>> um;
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> res;
        if (um.find(n) != um.end())
            return um[n];
        else if (n == 1)
            return um[n] = {"()"};
        else if (n == 2)
            return um[n] = {"()()", "(())"};

        for (int i = 1; i < n; ++i) {
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(n - i);
            for (const auto& l: left) {
                for (const auto& r: right) {
                    res.insert(l + r);
                }
            }
        }
        vector<string> inner = generateParenthesis(n - 1);
        for (const auto& i: inner)
            res.insert("(" + i + ")");
        return um[n] = vector<string>(res.begin(), res.end());
    }
};
