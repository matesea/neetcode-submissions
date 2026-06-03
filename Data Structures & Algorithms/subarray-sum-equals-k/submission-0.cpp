class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int,int> prefix;
        prefix[0] = 1;
        for (int& x: nums) {
            sum += x;
            if (prefix.find(sum - k) != prefix.end())
                res += prefix[sum - k];
            prefix[sum]++;
        }
        return res;
    }
};