class Solution {
public:
    int findMin(vector<int> &nums) {
        return binaryFindMin(nums, 0, nums.size()-1);
    }

    // The min/max element only exist in the rotated part.
    int binaryFindMin(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }

        int mid = (start + end) / 2;
        
        // left part in order
        if (nums[mid] > nums[end]) {
            return binaryFindMin(nums, mid+1, end);
        }
        // right part in order
        else {
            return binaryFindMin(nums, start, mid); 
        }
    }
};
