class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        result.clear();
        sort(nums.begin(), nums.end());
        dfs(nums, vector<int>(), target, 0);
        return result;
    }

    // we should pass combination by value, not by reference
    void dfs(vector<int>& nums, vector<int> combination, int target,int start_idx) {
        if (target == 0) {
            // find one combination
            result.push_back(combination);
            return;
        }
        else if (target < 0) {
            return;
        }

        for (int next_idx = start_idx; next_idx < nums.size(); next_idx++) {
            combination.push_back(nums[next_idx]);
            dfs(nums, combination, target-nums[next_idx], next_idx);
            combination.pop_back();
        }
    }
};
