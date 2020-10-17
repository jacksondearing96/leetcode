class Solution {
public:
    
    int findMin(vector<int>& nums, int start, int end) {
        if (start >= end) return nums[start];
        if (end - start == 1) return min(nums[start], nums[end]);
        
        int middle = start + (end - start) / 2;
        
        if (nums[start] > nums[middle]) {
            // Contradiction on the left.
            return findMin(nums, start, middle);
        } else if (nums[end] < nums[middle]) {
            // Contradiction on the right.
            return findMin(nums, middle, end);
        } else {
            // No contradiction.
            return nums[start];
        }
        
    }
    
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);     
    }
};
