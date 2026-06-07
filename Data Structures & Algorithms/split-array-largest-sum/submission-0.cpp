class Solution {
    int guess(vector<int>& nums, int m) {
        int count = 1;
        int current = 0;
        for (auto& x: nums) {
            if (current + x > m) {
                current = 0;
                ++count;
            }
            current += x;
        }
        return count;
    }
public:
    int splitArray(vector<int>& nums, int k) {
       int l = *max_element(nums.begin(), nums.end()); 
       int r = accumulate(nums.begin(), nums.end(), 0);
       while (l < r) {
        int mid = l + (r - l) / 2;
        int groups = guess(nums, mid);
        if (groups > k)
            l = mid+1;
        else r = mid;
       }
       return l;
    }
};