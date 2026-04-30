class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            q.push({nums[i], i});
            if (i >= k-1) {
                while (q.size() > 0 && q.top().second <= i - k)
                    q.pop();
                res.push_back(q.top().first);
            }
        }
        return res;
    }
};
