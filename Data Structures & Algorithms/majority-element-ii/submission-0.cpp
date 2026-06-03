class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int> count; 
       for (const auto& x: nums) {
        count[x]++;
       }
       vector<int> res;
       for (auto [key, value]: count) {
        if (value * 3 > n)
            res.push_back(key);
       }
       return res;
    }
};