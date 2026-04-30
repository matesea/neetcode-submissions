class Solution {
    bool isOperator(string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& token: tokens) {
            if (isOperator(token)) {
                int v2 = s.top();
                s.pop();
                int v1 = s.top();
                s.pop();
                switch (token[0]) {
                    case '+':
                        s.push(v1 + v2);
                        break;
                    case '-':
                        s.push(v1 - v2);
                        break;
                    case '*':
                        s.push(v1 * v2);
                        break;
                    case '/':
                        s.push(v1 / v2);
                        break;
                    default:
                        return -1;
                }
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
