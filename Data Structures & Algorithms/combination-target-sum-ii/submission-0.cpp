class Solution {
    vector<vector<int>> res;
    void rec(vector<int>& candidates, int i, int target, vector<int>& v) {
        if (!target)
            res.push_back(v);
        if (i >= candidates.size() || target <= 0)
            return;
        if (target >= candidates[i]) {
            v.push_back(candidates[i]);
            rec(candidates, i + 1, target - candidates[i], v);
            v.pop_back();
        }
        while (i + 1 < candidates.size() && candidates[i+1] == candidates[i])
            ++i;
        rec(candidates, i+1, target, v);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
       sort(candidates.rbegin(), candidates.rend()); 
       rec(candidates, 0, target, v);
       return res;
    }
};
