class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;
        for (auto& x: nums) {
            if (count.size() < 2 || count.find(x) != count.end()) {
                count[x]++;
                continue;
            }
            unordered_map<int,int> newcount;
            for (auto& entry: count) {
                entry.second--;
                if (entry.second > 0)
                    newcount[entry.first] = entry.second;
            }
            count = newcount;
        }
        vector<int> res;
        for (auto& entry: count) {
            int freq = 0;
            for (auto& x: nums) {
                if (x == entry.first)
                    freq++;
                if (freq * 3 > n)
                    break;
            }
            if (freq * 3 > n)
                res.push_back(entry.first);
        }
        return res;
    }
};