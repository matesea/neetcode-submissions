class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for (auto& c: s) {
            count[c - 'a']++;
        }
        priority_queue<pair<int,char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (count[i])
                pq.push({count[i], 'a' + i});
        }
        pair<int,char> prev = {0, ' '};
        string res;
        while (pq.size() > 0) {
            auto [_count, _char] = pq.top();
            pq.pop();
            res += _char;
            _count--;

            if (prev.first > 0)
                pq.push(prev);
            prev = {_count, _char};
        }
        if (res.size() == s.size())
            return res;
        return "";
    }
};