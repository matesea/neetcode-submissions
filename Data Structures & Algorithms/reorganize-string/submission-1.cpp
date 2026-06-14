class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for (auto& c: s)
            count[c-'a']++;
        auto cmp = [](const pair<int,char>& a, const pair<int,char>& b) -> bool {
            return a.first < b.first;
        };
        priority_queue<pair<int, char>,vector<pair<int,char>>,decltype(cmp)> pq(cmp);
        for (int i = 0; i < 26; ++i) {
            if (count[i])
                pq.push({count[i], 'a'+i});
        }
        string res;
        priority_queue<vector<unsigned int>,vector<vector<unsigned int>>,greater<vector<unsigned int>>> pending;
        while (pq.size() > 0) {
            auto t = pq.top();
            pq.pop();
            res += t.second;
            if (t.first > 1) {
                unsigned int idx = 1 + res.size();
                unsigned int _char = t.second;
                unsigned int _count = t.first - 1;
                pending.push({idx, _char, _count});
            }
            int i = res.size();
            while (pending.size() > 0) {
                if (pending.top()[0] > i)
                    break;
                auto v = pending.top();
                pending.pop();
                pq.push({v[2], v[1]});
            }
        }
        if (res.size() == s.size())
            return res;
        return "";
    }
};