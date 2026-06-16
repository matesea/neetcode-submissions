class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string res;
        while (pq.size() > 0) {
            int sz = res.size();
            pair<int,char> first = pq.top();
            pq.pop();
            if (sz >= 2 && res[sz - 2] == first.second && res[sz - 1] == first.second) {
                if (pq.empty()) break;
                pair<int,char> second = pq.top();
                pq.pop();
                res += second.second;
                if (second.first > 1)
                    pq.push({second.first - 1, second.second});
                pq.push(first);
            } else {
                res += first.second;
                if (first.first > 1)
                    pq.push({first.first - 1, first.second});
            }
        }
        return res;
    }
};