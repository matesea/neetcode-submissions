class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int res = 0;
        while (left < right) {
            res = max(res, (right - left) * min(heights[right], heights[left]));
            if (heights[left] < heights[right])
                left++;
            else right--;
        }
        return res;
    }
};
