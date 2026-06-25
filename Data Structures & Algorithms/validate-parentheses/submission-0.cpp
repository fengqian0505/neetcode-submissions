class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;

        for (auto& c : s) {
            if (c == '[' || c == '{' || c == '(') {
                sta.push(c);
            }
            else {
                if (!sta.empty() && isMatch(sta.top(), c)) {
                    sta.pop();
                }
                else {
                    return false;
                }
            }
        }

        return sta.empty();
    }

    bool isMatch(char c1, char c2) {
        if (c1 == '[' && c2 == ']') {
            return true;
        } 

        if (c1 == '{' && c2 == '}') {
            return true;
        } 
                
        if (c1 == '(' && c2 == ')') {
            return true;
        } 

        return false;
    }
};
