class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> q;
        unordered_map<int,int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
            if (m[nums[i]] == 1)
                q.push(nums[i]);
            if (i+1 < k) continue;
            if (i >= k) m[nums[i - k]]--;

            while (q.size() > 0 && m[q.top()] == 0)
                q.pop();
            res.push_back(q.top());
        }
        return res;
    }
};
