class Solution {
    bool eat(vector<int>& piles, int k, int h) {
        for (auto& b: piles) {
            h -= (b+k-1)/k;
            if (h < 0)
                return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int left = 1, right = *max_element(piles.begin(), piles.end());
       while (left < right) {
        int mid = left + (right - left) / 2;
        if (eat(piles, mid, h)) {
            right = mid;
        } else
            left = mid + 1;
       }
       return left;
    }
};
