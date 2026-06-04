class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n - 1; i >= 0; --i) {
            if (i >= n) nums1[i] = nums1[i-n];
            else nums1[i] = 0;
        }
        int i = n, j = 0, k = 0;
        while (i < m+n && j < n) {
            if (nums1[i] <= nums2[j])
                nums1[k] = nums1[i++];
            else nums1[k] =  nums2[j++];
            ++k;
        }
        if (i < m+n) {
            while (k < m+n)
                nums1[k++] = nums1[i++];
        }
        if (j < n) {
            while (k < m+n)
                nums1[k++] = nums2[j++];
        }
    }
};