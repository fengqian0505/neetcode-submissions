class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;

        for(const auto& c : s) {
            switch(c) {
                case '(':
                case '{':
                case '[':
                    sta.push(c);
                    break;
                case ')':
                    if (!sta.empty() && sta.top() == '(') {
                        sta.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case '}':
                    if (!sta.empty() && sta.top() == '{') {
                        sta.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                case ']':
                    if (!sta.empty() && sta.top() == '[') {
                        sta.pop();
                    }
                    else {
                        return false;
                    }
                    break;  
            }
        }

        return sta.empty();
    }
};
