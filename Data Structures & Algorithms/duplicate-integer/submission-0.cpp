class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for(auto num : nums) {
            if (num_set.find(num) != num_set.end()) {
                return true;
            }

            num_set.insert(num);
        }

        return false;
    }
};