class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;

        for(const auto& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            anagram_map[sorted_str].push_back(str);
        }

        vector<vector<string>> result;
        for(const auto& [key, value] : anagram_map) {
            result.push_back(move(value));
        }

        return result;
    }
};
