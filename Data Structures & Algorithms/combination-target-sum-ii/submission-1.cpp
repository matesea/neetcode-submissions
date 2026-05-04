class Solution {
    vector<vector<int>> res;
    void rec(vector<int>& candidates, int idx, int target, vector<int>& v) {
        if (!target) {
            res.push_back(v);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i-1])
                continue;
            if (candidates[i] > target)
                break;
            v.push_back(candidates[i]);
            rec(candidates, i + 1, target - candidates[i], v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
       sort(candidates.begin(), candidates.end()); 
       rec(candidates, 0, target, v);
       return res;
    }
};
