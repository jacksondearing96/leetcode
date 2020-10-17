class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if (nums.size() <= 1)
            return false;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size()-1; i++)
        {
            if (nums.at(i) == nums.at(i+1))
                return true;
        }
        return false;
        
    }
};
