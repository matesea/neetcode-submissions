class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit+1, 0);
        for (auto& p: people) {
            count[p]++;
        }
        int res = 0;
        int left = 0, right = limit;
        while (left < right) {
            while (left < right && !count[left]) left++;
            while (left < right && !count[right]) right--;
            if (left >= right) break;
            if (left + right <= limit) {
                count[left]--; count[right]--;
            } else if (count[right] >= 2 && right * 2 <= limit) {
                count[right] -= 2;
            } else {
                count[right]--;
            }
            res++;
        }
        while (count[left]) {
            if (count[left] >= 2 && left * 2 <= limit) {
                count[left] -= 2;
            } else {
                count[left]--;
            }
            res++;
        }
        return res;
    }
};