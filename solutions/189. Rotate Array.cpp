class Solution {
public:
    
    vector<int>& rotateOnce(vector<int>& nums)
    {
        int temp = nums.at(nums.size() - 1);
        for (int i = nums.size()-1; i > 0; i--)
        {
            nums.at(i) = nums.at(i-1);
        }
        nums.at(0) = temp;
        return nums;
    }
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        
        vector<int> res;
        
        for (int i=0; i<nums.size(); i++)
        {
            res.push_back(nums.at((nums.size() - k + i) % (nums.size())));
        }
        nums = res;
    }
};
