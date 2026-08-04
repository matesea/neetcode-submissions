class Solution {
    bool dfs(vector<int>& bills, int i, unordered_map<int,int>& changes) {
        if (i == bills.size())
            return true;
        if (bills[i] == 5) {
            changes[5]++;
            return dfs(bills, i+1, changes);
        }
        if (bills[i] == 10) {
            if (changes[5] <= 0)
                return false;
            changes[5]--;
            changes[10]++;
            return dfs(bills, i+1, changes);
        }
        if (changes[5] <= 0)
            return false;
        if (changes[10] > 0 && changes[5] > 0) {
            changes[10]--;
            changes[5]--;
            if (dfs(bills, i + 1, changes)) return true;
            changes[10]++;
            changes[5]++;
        }
        if (changes[5] > 2) {
            changes[5] -= 3;
            if (dfs(bills, i + 1, changes)) return true;
            changes[5] += 3;
        }
        return false;
    }
public:
    bool lemonadeChange(vector<int>& bills) {
       unordered_map<int,int> changes; 
       return dfs(bills, 0, changes);
    }
};