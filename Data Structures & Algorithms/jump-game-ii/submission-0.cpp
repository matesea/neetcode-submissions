class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n, INT_MAX);
        steps[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, 0});
        while (pq.size() > 0) {
            auto [s, i] = pq.top();
            pq.pop();
            if (i+1 == n) break;
            for (int j = i + 1; j <= min(n-1, i + nums[i]); ++j) {
                if (s + 1 < steps[j]) {
                    steps[j] = s + 1;
                    pq.push({steps[j], j});
                }
            }
        }
        return steps[n-1];
    }
};
