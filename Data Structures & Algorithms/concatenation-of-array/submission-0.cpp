class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        for (auto& x: nums)
            res.push_back(x);
        for (auto& x: nums)
            res.push_back(x);
        return res;
    }
};