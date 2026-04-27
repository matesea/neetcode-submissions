class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        for (int i = 0; i < nums.size(); ++i) {
            int& e = nums[i];
            if (s.find(target - e) != s.end())
                return {s[target - e], i};
            s[e] = i;
        }
        return {-1, -1};
    }
};
