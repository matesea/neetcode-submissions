class Solution {
    unordered_set<int> seen;
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        if (seen.find(n) != seen.end())
            return false;
        seen.insert(n);
        int next = 0, orig_n = n;
        while (n > 0) {
            int d = n % 10;
            next += (d * d);
            n /= 10;
        }
        return isHappy(next);
    }
};
