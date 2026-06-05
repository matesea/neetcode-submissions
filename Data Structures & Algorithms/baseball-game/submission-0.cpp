class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for (auto& o: operations) {
            if (o == "+") {
                if (scores.size() >= 2) scores.push_back(scores[scores.size() - 2] + scores[scores.size() - 1]);
            } else if (o == "C") {
                if (scores.size() > 0) scores.pop_back();
            } else if (o == "D") {
                if (scores.size() > 0) scores.push_back(scores.back() * 2);
            } else
                scores.push_back(stoi(o));
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};