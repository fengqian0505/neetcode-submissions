class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(auto& num : nums) {
            s.insert(num);
        }

        int max_len = 0;

        for(auto& num : s) {
            int len = 1;
            if (s.find(num-1) == s.end()) {
                // num will be the start of the consecutive sequence
                int next_value = num+1;
                while(s.find(next_value) != s.end()) {
                    len++;
                    next_value++;
                }
            }

            max_len = max(len, max_len);
        }

        return max_len;
    }
};
