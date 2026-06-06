class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (auto& a: asteroids) {
            if (s.empty() || !(s.back() > 0 && a < 0)) {
                s.push_back(a);
                continue;
            }
            while (!s.empty() && s.back() > 0 && a < 0) {
                if (abs(s.back()) < abs(a)) {
                    s.pop_back();
                } else if (abs(s.back()) == abs(a)) {
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