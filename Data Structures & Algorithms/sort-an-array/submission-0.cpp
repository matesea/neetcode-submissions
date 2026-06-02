class Solution {
    void partition(vector<int>& nums, int pivot, int left, int right) {
        if (left >= right)
            return;
        if (left+1 == right) {
            if (nums[left] > nums[right])
                swap(nums[left], nums[right]);
            return;
        }
        int i = left, j = left, k = right;
        while (j <= k) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                ++i; ++j;
            } else if (nums[j] > pivot) {
                swap(nums[j], nums[k]);
                --k;
            } else {
                ++j;
            }
        }
        // cout << "pivot=" << pivot << ", i=" << i << ", j=" << j << ", k=" << k << endl;
        quicksort(nums, left, i-1);
        quicksort(nums, k+1, right);
    }
    void quicksort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        if (left+1 == right) {
            if (nums[left] > nums[right])
                swap(nums[left], nums[right]);
            return;
        }
        int n = right - left + 1;
        int pivot = nums[left];
        partition(nums, pivot, left, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};