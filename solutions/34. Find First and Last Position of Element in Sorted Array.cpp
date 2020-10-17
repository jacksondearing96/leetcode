class Solution {
public:
    
    int binarySearch(vector<int>& nums, int start, int end, int target)
    {
        int middle;
        while (start <= end)
        {
            middle = start + (end - start) / 2;
            if (nums.at(middle) == target)
                return middle;
            
            if (nums.at(middle) > target)
            {
                end = middle - 1;
            }
            else if (nums.at(middle) < target)
            {
                start = middle + 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int min = -1;
        int max = -1;
        
        int end = nums.size() - 1;
        while (binarySearch(nums, 0, end, target) != -1)
        {
            min = binarySearch(nums, 0, end, target);
            end = min - 1;
        }
        
        int start = 0;
        end = nums.size()-1;
        while (binarySearch(nums, start, end, target) != -1)
        {
            max = binarySearch(nums, start, end, target);
            start = max + 1;
        }
        
        return {min, max};
    }
};
