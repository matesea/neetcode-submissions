class Solution {
    int partition(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];
        int p = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[p++]);
            }
        }
        swap(nums[p], nums[right]);
        if (p == k)
            return nums[p];
        else if (p < k)
            return partition(nums, p+1, right, k);
        else
            return partition(nums, left, p - 1, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
