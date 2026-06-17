class Solution {
    bool dfs(unordered_map<int,int>& freq, int current, int target, int i) {
        if (current == target && i == 3) return true;
        if (current == target)
            return dfs(freq, 0, target, i + 1);
        for (auto& [val, count]: freq) {
            if (count > 0 && current + val <= target) {
                count--;
                if (dfs(freq, current + val, target, i)) return true;
                count++;
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
       unsigned long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
       if (sum % 4) return false;
       unsigned long long target = sum / 4;
       unordered_map<int,int> freq;
       for (auto& m: matchsticks) {
        freq[m]++;
       }
       return dfs(freq, 0, target, 0);
       /*
       vector<int> dp(1+target, 0);
       dp[0] = 1;
       for (auto& m: matchsticks) {
        for (int i = target; i >= 0; --i) {
            if (dp[i] && i + m <= target)
                dp[i+m] += dp[i];
        }
       }
       return dp[target] >= 4;
       */
    }
};