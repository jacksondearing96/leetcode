class Solution {
public:
/*
​
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
​
*/
    int nextLargestIndex(const vector<int>& nums, int i) {
        int base = nums[i];
        int index = -1;
        int nextLargest = INT_MAX;
        
        ++i;
        for (; i < nums.size(); ++i) {
            if (nums[i] > base && nums[i] < nextLargest) {
                index = i; 
                nextLargest = nums[i];
            }
        }
        return index;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int prev = INT_MIN;
        int i = -1;
        
        for (i = nums.size() - 1; i >= 0; --i) {
            if (prev <= nums[i]) { 
                prev = nums[i];
                continue;
            }
            
            int next_largest_index = nextLargestIndex(nums, i); 
            if (next_largest_index != -1) swap(nums, i, next_largest_index);
            break;
        }
        sort(nums.begin() + i + 1, nums.end());
    }
};
