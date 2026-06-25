class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int max_len = 0;
        
        int left = 0;
        for(int right = 0; right < s.size(); ++right) {
            if (last_seen.find(s[right]) != last_seen.end()) {
                // see this char before,
                left = max(left, last_seen[s[right]] + 1);
            }
            last_seen[s[right]] = right;
            int len = right - left + 1;
            max_len = max(max_len, len);
        }

        return max_len;
    }
};
