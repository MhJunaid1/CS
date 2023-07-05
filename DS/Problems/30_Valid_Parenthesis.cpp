class Solution {
public:
    bool isValid(string s) {
        stack<char> stk1;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk1.push(s[i]);
            } 
            else if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && !stk1.empty()) 
            {
                if (s[i] == ')') {
                    if (stk1.top() == '(') {
                        stk1.pop();
                    } else {
                        return false;
                    }
                }
                if (s[i] == ']') {
                    if (stk1.top() == '[') {
                        stk1.pop();
                    } else {
                        return false;
                    }
                }
                if (s[i] == '}') {
                    if (stk1.top() == '{') {
                        stk1.pop();
                    } else {
                        return false;
                    }
                }
            }
            else{
                return false;
            }
            i++;
        }
        if (stk1.empty()) {
            return true;
        }
        return false;
    }
};