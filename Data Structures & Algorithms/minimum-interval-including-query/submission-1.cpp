class Solution {
    int help(vector<vector<int>>& i, int q) {
        int n = i.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (i[m][1] < q)
                l = m + 1;
            else
                r = m;
        }
        int res = INT_MAX;
        while (l < n) {
            if (i[l][0] <= q && q <= i[l][1]) res = min(res, i[l][1] - i[l][0] + 1);
            ++l;
        }
        return res == INT_MAX ? -1 : res;
    }
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
       sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
        return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
       }); 
       vector<int> res;
       for (auto& q: queries) {
        res.push_back(help(intervals, q));
       }
       return res;
    }
};
