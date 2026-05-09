class Solution {
    bool dist1(const string& a, const string& b) {
        int k = 1, i;
        for (i = 0; i < a.size() && k >= 0; ++i) {
            if (a[i] != b[i]) --k;
        }
        return i == a.size() && k == 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_map<string,vector<string>> adj;

       if (beginWord == endWord) return 0;
       if (words.find(endWord) == words.end()) return 0;

       for (int i = 0; i < wordList.size(); ++i) {
        if (dist1(beginWord, wordList[i]))
            adj[beginWord].push_back(wordList[i]);
        if (dist1(wordList[i], endWord))
            adj[wordList[i]].push_back(endWord);
        for (int j = i + 1; j < wordList.size(); ++j) {
            if (dist1(wordList[i], wordList[j])) {
                adj[wordList[i]].push_back(wordList[j]);
                adj[wordList[j]].push_back(wordList[i]);
            }
        }
       }

       queue<string> q;
       unordered_set<string> visited;
       int steps = 0;
       q.push(beginWord);

       while (q.size() > 0) {
        int sz = q.size();
        while (sz-- > 0) {
            string current = q.front();
            q.pop();
            // cout << current << ": " << steps << endl;
            if (current == endWord)
                return steps + 1;
            for (const auto& next: adj[current]) {
                if (visited.find(next) != visited.end())
                    continue;
                visited.insert(next);
                q.push(next);
            }
        }
        ++steps;
       }
       return 0;
    }
};
