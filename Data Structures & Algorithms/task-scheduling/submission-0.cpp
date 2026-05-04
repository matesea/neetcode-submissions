class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto& t: tasks) {
            freq[t - 'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int i = 0;
        int maxFreq = freq[0] - 1;
        int idle = (freq[0] - 1) * n;
        for (i = 1; i < 26 && freq[i] > 0; ++i) {
            idle -= min(freq[i], maxFreq);
        }
        return idle > 0 ? tasks.size() + idle : tasks.size();
    }
};
