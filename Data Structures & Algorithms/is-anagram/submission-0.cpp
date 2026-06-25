class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> char_map;
        for(char c : s) {
            char_map[c]++;
        }

        for (char c : t) {
            char_map[c]--;
            if (char_map[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
