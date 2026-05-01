class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l+1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[l] < nums[r])
                break;
            if (nums[mid] > nums[l])
                l = mid + 1;
            else r = mid;
        }
        return nums[l] < nums[r] ? nums[l] : nums[r];
    }
};
