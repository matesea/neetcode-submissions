class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int i = 0, n = nums.size();
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == nums[i]) ++j;
            nums[k++] = nums[i];
            i = j;
        }
        return k;
    }
};