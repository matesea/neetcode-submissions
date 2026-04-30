class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> d;
       int left = 0;
       vector<int> res;
       for (int right = 0; right < nums.size(); ++right) {
        while (d.size() > 0 && nums[d.back()] < nums[right])
            d.pop_back();
        d.push_back(right);
        if (d.front() < left)
            d.pop_front();
        if (right + 1 >= k) {
            res.push_back(nums[d.front()]);
            left++;
        }
       }
       return res;
    }
};
