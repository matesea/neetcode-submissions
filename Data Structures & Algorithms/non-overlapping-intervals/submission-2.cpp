class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int last = intervals[0][1], removed = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (last > intervals[i][0]) {
                removed++;
                last = min(last, intervals[i][1]);
            } else
                last = intervals[i][1];
        }
        return removed;
    }
};
