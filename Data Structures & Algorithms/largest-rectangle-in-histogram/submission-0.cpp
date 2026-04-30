class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                res = max(res, h * (s.empty()? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return res;
    }
};
