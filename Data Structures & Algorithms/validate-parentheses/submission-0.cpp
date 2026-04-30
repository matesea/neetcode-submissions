class Solution {
public:
    bool isValid(string s) {
       stack<char> ss; 
       for (auto& c: s) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                ss.push(c);
                break;
            case ')':
                if (ss.empty() || ss.top() != '(')
                    return false;
                ss.pop();
                break;
            case '}':
                if (ss.empty() || ss.top() != '{') return false;
                ss.pop();
                break;
            case ']':
                if (ss.empty() || ss.top() != '[') return false;
                ss.pop();
                break;
        }
       }
       return ss.empty();
    }
};
