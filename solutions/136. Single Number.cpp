class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if (nums.size() == 1)
            return nums.at(0);
        
        int walker = 0;
        int runner = 1;
        
        while (true)
        {
            if (walker != runner)
            {
                if (nums.at(walker) == nums.at(runner)) 
                {
                    if (walker > runner)
                    {
                        nums.erase(nums.begin() + walker);
                        nums.erase(nums.begin() + runner);
                    }
                    else 
                    {
                        nums.erase(nums.begin() + runner);
                        nums.erase(nums.begin() + walker);
                    } 
                }
            }
            
            
            if (nums.size() == 1)
                return nums.at(0);
            
            walker += 1;
            runner += 2;
            
            if (walker >= nums.size())
                walker = 0;
            
            if (runner >= nums.size())
                runner = 0;
        }
    }
};
