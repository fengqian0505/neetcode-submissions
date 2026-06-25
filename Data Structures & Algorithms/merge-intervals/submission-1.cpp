class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& inter1, const auto& inter2) {
            if (inter1[0] == inter2[0]) {
                return inter1[1] < inter2[1];
            }
            else {
                return inter1[0] < inter2[0]; 
            }
        });

        vector<vector<int>> result;
        int curr_idx = 0;
        while (curr_idx < intervals.size()) {
            int start = intervals[curr_idx][0];
            int end = intervals[curr_idx][1];

            int next_idx = curr_idx + 1;
            while (next_idx < intervals.size() && intervals[next_idx][0] <= end) { // find overlap intervals
                end = max(intervals[next_idx][1], end);
                next_idx++;
            }

            curr_idx = next_idx;
            result.push_back({start, end});
        }

        return result;
    }
};
