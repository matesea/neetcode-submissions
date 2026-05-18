class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(1+n, 0);
        int offset = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == 2 * offset) offset = i;
            res[i] = 1 + res[i - offset];
        }
        return res;
    }
};
