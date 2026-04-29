class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int n = height.size();
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (s.size() > 0 && height[s.top()] <= height[i]) {
                int j = s.top();
                s.pop();
                if (s.size() > 0) {
                    int left = height[s.top()];
                    int right = height[i];
                    int h = min(left, right) - height[j];
                    res += h * (i - s.top() - 1);
                }
            }
            s.push(i);
        }
        return res;
    }
};
