class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> t = {0, 0, 0};
        for (auto& tt: triplets) {
            if (tt[0] > target[0] || tt[1] > target[1] || tt[2] > target[2])
                continue;
            t[0] = max(t[0], tt[0]);
            t[1] = max(t[1], tt[1]);
            t[2] = max(t[2], tt[2]);
        }
        return target[0] == t[0] && target[1] == t[1] && target[2] == t[2];
    }
};
