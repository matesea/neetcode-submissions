class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int  n = nums.size();
        int l = 0, r = n; 
        while (l < r) {
            int mid = (l + r)/2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                r = mid;
            else l = mid +1;
        }
        return l;
    }
};