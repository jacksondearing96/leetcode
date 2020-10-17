class Solution {
public:
    void swap(vector<int>& vec, int i, int j) {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
    
    void moveZeroes(vector<int>& nums) {
        
        int start = 0;
        
        while (start < nums.size() && nums[start] != 0) ++start;
        if (start == nums.size()) return;
​
        // Now start is the index of the first zero.
        int end = start + 1;
        while (end < nums.size())
        {
            if (nums[end] != 0)
            {
                swap(nums, start, end);
                ++start;
            }
            ++end;
        }
        
    }
};
