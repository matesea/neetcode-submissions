class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res = 0;
        for (auto& c: nums) {
            if (!mp[c]) {
                mp[c] = mp[c-1] + mp[c+1] + 1;
                mp[c - mp[c-1]] = mp[c];
                mp[c + mp[c+1]] = mp[c];
                res = max(res, mp[c]);
            }
        }
        return res;
    }
};
