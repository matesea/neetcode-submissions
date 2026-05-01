class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[r]) {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else r = mid - 1;
            } else {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else l = mid + 1;
            }
        }
        return 0 <= l && l < n && nums[l] == target ? l :
            (0 <= r && r < n && nums[r] == target) ? r : -1;
    }
};
