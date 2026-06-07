class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
       int lo = 0, hi = nums.size() - 1; 
       while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] == target) return true;
        if (nums[mid] == nums[hi])
            --hi;
        else if (nums[mid] < nums[hi]) {
            if (target < nums[mid] || nums[hi] < target)
                hi = mid - 1;
            else lo = mid + 1;
        } else if (nums[mid] > nums[hi]) {
            if (nums[lo] < target && target < nums[mid])
                hi = mid - 1;
            else lo = mid + 1;
        }
       }
       return 0 <= lo && lo < n && nums[lo] == target || 0 <= hi && hi < n && nums[hi] == target;
    }
};