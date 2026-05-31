class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size(), n = nums2.size(); 
       int total = m + n;
       int half = (total+1) / 2;
       if (m > n) return findMedianSortedArrays(nums2, nums1);

       int left = 0, right = m;

       while (left <= right) {
        int i = left + (right - left) / 2;
        int j = half - i;

        int nums1_left = (i > 0 ? nums1[i-1] : INT_MIN);
        int nums1_right = (i < m ? nums1[i] : INT_MAX);
        int nums2_left = (j > 0 ? nums2[j-1] : INT_MIN);
        int nums2_right = (j < n ? nums2[j] : INT_MAX);

        if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
            if (total % 2)
                return max(nums1_left, nums2_left);
            else return (double)0.5 * (max(nums1_left, nums2_left) + min(nums1_right, nums2_right));
        } else if (nums1_left > nums2_right)
            right = i - 1;
        else left = i + 1;
       }
       return -1;
    }
};
