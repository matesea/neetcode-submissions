class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k+1)
                m[nums[i-k-1]]--;
            if (m.find(nums[i]) != m.end() && m[nums[i]] > 0)
                return true;
            m[nums[i]]++;
        }
        return false;
    }
};