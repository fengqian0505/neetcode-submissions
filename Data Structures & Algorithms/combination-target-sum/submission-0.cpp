class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        result.clear();

        sort(nums.begin(), nums.end());
        for (const auto& num : nums) {
            dfs(nums, vector<int>(), target, num);
        }

        return result;
    }

    // we should pass combination by value, not by reference
    void dfs(vector<int>& nums, vector<int> combination, int target,int num) {
        if (combination.size() > 0 && num < combination.back()) {
            // since the nums is ordered, so the combination should in increasing order
            return;
        }
        
        if (target == num) {
            // find one combination
            combination.push_back(num);
            result.push_back(combination);
            return;
        }
        else if (target < num) {
            return;
        }

        combination.push_back(num);
        for (const auto& next_num : nums) {
            dfs(nums, combination, target-num, next_num);
        }
        combination.pop_back();
    }
};
