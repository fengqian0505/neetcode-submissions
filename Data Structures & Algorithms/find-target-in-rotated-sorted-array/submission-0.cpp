class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size()-1);
    }

    int binary_search(vector<int>& nums, int target, int start, int end) {
        if (start > end) {
            return -1;
        }

        int mid = (start + end) / 2;
        
        if (nums[mid] == target) 
        {
            return mid;
        }

        // left part rotated
        if (nums[mid] < nums[end]) {
            if (target > nums[mid] && target <= nums[end]) {
                return binary_search(nums, target, mid+1, end);
            }
            else {
                return binary_search(nums, target, start, mid-1);
            }
        }
        // right part rotated
        else {
            if (target >= nums[start] && target < nums[mid]) {
                return binary_search(nums, target, start, mid-1);
            }
            else {
                return binary_search(nums, target, mid+1, end);
            }
        }

        return -1;
    }
};
