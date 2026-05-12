class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;
        if (hand.size() % groupSize)
            return false;
        for (auto& n: hand)
            m[n]++;
        for (int i = 0; i < hand.size()/groupSize; ++i) {
            int start = m.begin()->first;
            for (int j = start; j < start + groupSize; ++j) {
                if (m.find(j) == m.end() || m[j] == 0)
                    return false;
                m[j]--;
                if (m[j] == 0)
                    m.erase(j);
            }
        }
        return true;
    }
};
