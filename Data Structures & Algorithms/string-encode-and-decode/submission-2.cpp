class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for(auto& str : strs) {
            res += to_string(str.size());
            res += '#';
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while(i < s.size()) {
            // decode string size
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int strLen = stoi(s.substr(i, j-i));

            // skip #
            j++;

            // decode string
            string str = s.substr(j, strLen);
            strs.push_back(str);
            i = j+strLen;
        }

        return strs;
    }
};
