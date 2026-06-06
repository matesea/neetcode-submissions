class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (auto& a: asteroids) {
            while (!s.empty() && s.back() > 0 && a < 0) {
                int diff = s.back() + a;
                if (diff < 0) {
                    s.pop_back();
                } else if (!diff) {
                    s.pop_back();
                    a = 0;
                } else a = 0;
            }
            if (a != 0)
                s.push_back(a);
        }
        return s;
    }
};