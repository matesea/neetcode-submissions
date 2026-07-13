class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) -> bool {
            return a.first < b.first || a.first == b.first && a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp), tmp(cmp);
        for (int i = 0; i < profits.size(); ++i) {
            pq.push({profits[i], capital[i]});
        }
        while (k > 0) {
            while (pq.size() > 0 && pq.top().second > w) {
                tmp.push(pq.top());
                pq.pop();
            }
            if (!pq.size()) break;
            auto t = pq.top();
            pq.pop();
            // cout << "pick profit:" << t.first << ", capital:" << t.second << endl;
            w += t.first;
            --k;
            while (tmp.size()) {
                pq.push(tmp.top());
                tmp.pop();
            }
        }
        return w;
    }
};