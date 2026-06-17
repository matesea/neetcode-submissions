class Solution {
    bool dfs(vector<int>& m, int i, int target, int s1, int s2, int s3, int s4) {
        if (i == m.size()) return true;
        if (s1 + m[i] <= target && dfs(m, i+1, target, s1+m[i], s2, s3, s4)) return true;
        if (s1 != s2 && s2 + m[i] <= target && dfs(m, i+1, target, s1, s2+m[i], s3, s4)) return true;
        if (s1 != s3 && s2 != s3 && s3 + m[i] <= target && dfs(m, i+1, target, s1, s2, s3+m[i], s4)) return true;
        if (s1 != s4 && s2 != s4 && s3 != s4 && s4 + m[i] <= target && dfs(m, i+1, target, s1, s2, s3, s4+m[i]))
            return true;
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
       unsigned long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
       if (sum % 4) return false;
       if (*max_element(matchsticks.begin(), matchsticks.end()) > sum / 4) return false;
       sort(matchsticks.rbegin(), matchsticks.rend());
       return dfs(matchsticks, 0, sum / 4, 0, 0, 0, 0);
    }
};