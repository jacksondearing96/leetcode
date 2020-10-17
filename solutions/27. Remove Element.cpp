class Solution {
public:
        
    int removeElement(vector<int>& nums, int val) {
        
        bool swapMade = true;
        int len = nums.size();
        
        while (swapMade)
        {
            swapMade = false;
            for (int i=0 ; i<len ; i++)
            {
                if (nums.at(i) == val)
                {
                    swapMade = true;
                    
                    if (i != len-1)
                    {
                        int temp = nums.at(i);
                        nums.at(i) = nums.at(i+1);
                        nums.at(i+1) = temp;
                    }
                }
                
                if (i == len-1 && nums.at(i) == val)
                    len--;
            }
        }
        
        return len;
    }
};
