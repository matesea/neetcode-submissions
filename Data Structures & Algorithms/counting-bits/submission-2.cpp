class Solution {
    int help(int x) {
        int res = 0;
        while (x > 0) {
            x -= (x & -x);
            ++res;
        }
        return res;
    }
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; ++i) {
            res.push_back(help(i));
        }
        return res;
    }
};
