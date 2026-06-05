class Solution {
public:
    int calPoints(vector<string>& operations) {
       stack<int> s; 
       int res = 0;
       for (auto& o: operations) {
            if (o == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a); s.push(a+b);
                res += a+b;
            } else if (o == "C") {
                res -= s.top();
                s.pop();
            } else if (o == "D") {
                res += s.top() * 2;
                s.push(s.top() * 2);
            } else {
                s.push(stoi(o));
                res += s.top();
            }
       }
       return res;
    }
};