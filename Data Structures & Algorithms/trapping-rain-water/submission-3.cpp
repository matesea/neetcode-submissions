class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = height[0], rightMax = height[right];
        int res = 0;
        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                res += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                res += rightMax - height[right];
            }
        }
        return res;
    }
};
