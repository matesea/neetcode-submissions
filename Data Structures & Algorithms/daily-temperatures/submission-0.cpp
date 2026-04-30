class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<int> s; 
       int n = temperatures.size();
       vector<int> res(n, 0);
       for (int i = 0; i < n; ++i) {
        while (s.size() > 0 && temperatures[s.top()] < temperatures[i]) {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
       }
       return res;
    }
};
