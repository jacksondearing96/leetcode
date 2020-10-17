class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        
        bool nums_present[nums.size() + 1];
        
        for (bool& num_present : nums_present)
        {
            num_present = false;
        }
        
        for (int num : nums)
        {
            nums_present[num] = true;
        }
        
        for (int index = 0; index < nums.size() + 1; ++index)
        {
            if (!nums_present[index]) return index;
        }
        return -1;
    }
};
