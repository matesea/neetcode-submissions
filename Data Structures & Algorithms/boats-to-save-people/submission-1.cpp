class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit+1, 0);
        for (auto& p: people) {
            count[p]++;
        }
        int idx = 0, i = 0;
        while (idx < people.size()) {
            while (!count[i]) ++i;
            people[idx++] = i;
            count[i]--;
        }
        int left = 0, right = people.size() - 1;
        int res = 0;
        while (left <= right) {
            int reminder = limit - people[right--];
            if (reminder >= people[left]) {
                left++;
            }
            res++;
        }
        return res;
    }
};