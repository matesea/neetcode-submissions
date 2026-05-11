class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<bool>> adj(26, vector<bool>(26, false));
        vector<bool> chars(26, false); 
        int count = 0;
        vector<int> indegree(26, 0);
        for (auto& w: words) {
            for (auto& c: w) {
                if (!chars[c - 'a']) {
                    chars[c - 'a'] = true;
                    count++;
                }
            }
        }
        for (int i = 0; i+1 < words.size(); ++i) {
            string& w1 = words[i];
            string& w2 = words[i+1];
            int minLength = min(w1.size(), w2.size());
            if (w1.size() > minLength && w1.substr(0, minLength) == w2)
                return "";
            int j = 0;
            while (j < minLength && w1[j] == w2[j]) ++j;
            if (j < minLength && !adj[w1[j] - 'a'][w2[j] - 'a']) {
                adj[w1[j] - 'a'][w2[j] - 'a'] = true;
                indegree[w2[j] - 'a']++;
            }
        }
        queue<int> q;
        string res;
        for (int i = 0; i < 26; ++i) {
            if (chars[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() > 0) {
            char c = q.front();
            q.pop();
            res.push_back('a' + c);
            for (int i = 0; i < 26; ++i) {
                if (adj[c][i]) {
                    indegree[i]--;
                    if (!indegree[i]) {
                        q.push(i);
                    }
                }
            }
        }
        return res.size() == count ? res : "";
    }
};
