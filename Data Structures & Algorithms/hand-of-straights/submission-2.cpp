class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;
        if (hand.size() % groupSize)
            return false;
        for (auto& n: hand)
            m[n]++;
        while (m.size() > 0) {
            int start = m.begin()->first, count = m.begin()->second;
            for (int j = start; j < start + groupSize; ++j) {
                if (m.find(j) == m.end() || m[j] < count)
                    return false;
                m[j] -= count;
                if (m[j] == 0) m.erase(j);
            }
        }
        return true;
    }
};
