class Solution {
    int ship(vector<int>& w, int cap) {
        int res = 1;
        int current = 0;
        for (auto& ww: w) {
            if (current + ww <= cap) {
                current += ww;
            } else {
                res++;
                current = ww;
            }
        }
        return res;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int lo = *max_element(weights.begin(), weights.end()); 
       int hi = accumulate(weights.begin(), weights.end(), 0);
       while (lo < hi) {
        int mid = (lo + hi) / 2;
        int s = ship(weights, mid);
        // cout << "mid=" << mid << ", s=" << s << endl;
        if (s <= days) hi = mid;
        else lo = mid + 1;
       }
       return lo;
    }
};