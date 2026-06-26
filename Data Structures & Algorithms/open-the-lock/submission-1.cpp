class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> seen;
        queue<string> q;
        int steps = 0;
        
        if (dead.find("0000") != dead.end())
            return -1;

        q.push("0000");
        seen.insert("0000");

        while (q.size() > 0) {
            int sz = q.size();
            while (sz-- > 0) {
                string s = q.front();
                q.pop();

                if (s == target)
                    return steps;

                for (int i = 0; i < 4; ++i) {
                    char digit = s[i] - '0';
                    string next(s);
                    next[i] = '0' + (digit + 1) % 10;
                    if (seen.find(next) == seen.end() && dead.find(next) == dead.end()) {
                        q.push(next);
                        seen.insert(next);
                    }
                    next = s;
                    next[i] = '0' + (digit + 9) % 10;
                    if (seen.find(next) == seen.end() && dead.find(next) == dead.end()) {
                        q.push(next);
                        seen.insert(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};