class Solution {
public:
    int findMin(vector<int> &nums) {
        return binaryFindMin(nums, 0, nums.size()-1);
    }

    int binaryFindMin(vector<int>& nums, int start, int end) {
        if (start > end) {
            return INT_MAX;
        }

        // if this sub-array in order
        if (nums[start] <= nums[end]) {
            return nums[start];
        }

        // if this sub-array is rorated
        int mid = (start + end) / 2;
        
        // lef part in order
        if (nums[start] <= nums[mid]) {
            return min(nums[start], binaryFindMin(nums, mid+1, end));
        }
        // right part in order
        else {
            return min(nums[mid], binaryFindMin(nums, start, mid-1)); 
        }
    }
};
