class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> m;
        int n = equations.size();
        unordered_set<string> variables;
        for (int i = 0; i < equations.size(); ++i) {
            m[equations[i][0]][equations[i][1]] = values[i];
            m[equations[i][1]][equations[i][0]] = 1.0 / values[i];
            variables.insert(equations[i][0]);
            variables.insert(equations[i][1]);
            m[equations[i][0]][equations[i][0]] = 1.0;
            m[equations[i][1]][equations[i][1]] = 1.0;
        }

        for (auto& i: variables) {
            for (auto& j: variables) {
                for (auto& k: variables) {
                    if (m.find(i) == m.end() || m[i].find(j) == m[i].end())
                        continue;
                    if (m.find(j) == m.end() || m[j].find(k) == m[j].end())
                        continue;
                    m[i][k] = m[i][j] * m[j][k];
                    m[k][i] = 1.0 / m[i][k];
                }
            }
        }
        vector<double> res;
        for (auto& q: queries) {
            string& u = q[0];
            string& v = q[1];
            if (m.find(u) == m.end() || m[u].find(v) == m[u].end()) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(m[u][v]);
        }
        return res;
    }
};