class Solution {
    unordered_map<char,unordered_set<char>> adj; 
    unordered_map<char,bool> visited;
    string s;

    bool dfs(char c) {
        if (visited.find(c) != visited.end())
            return visited[c];
        visited[c] = true;
        for (auto& next: adj[c]) {
            if (dfs(next))
                return true;
        }
        visited[c] = false;
        s.push_back(c);
        return false;
    }

public:
    string foreignDictionary(vector<string>& words) {
       for (auto& w: words) {
        for (auto& c: w) {
            adj[c] = {};
        }
       }
       for (int i = 0; i+1 < words.size(); ++i) {
        string &w1 = words[i], &w2 = words[i+1];
        int minLength = min(w1.size(), w2.size());
        if (w1.size() > minLength && w1.substr(0, minLength) == w2)
            return "";
        for (int j = 0; j < minLength; ++j) {
            if (w1[j] != w2[j]) {
                adj[w1[j]].insert(w2[j]);
                break;
            }
        }
       }
       for (auto [key, value]: adj) {
        if (dfs(key))
            return "";
       }
       reverse(s.begin(), s.end());
       return s;
    }
};
