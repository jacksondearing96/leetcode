class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        bool swap = true;
        int k = 1;
        
        while (swap)
        {
            swap = false;
            for (int i=1 ; i<nums.size()-k ; i++)
            {
                if (nums.at(i) <= nums.at(i-1))
                {
                    int temp = nums.at(i+1);
                    nums.at(i+1) = nums.at(i);
                    nums.at(i) = temp;
                    swap = true;
                }   
            }
            if (swap)
                k++;
        }
​
        
        int count = 1;
        for (int i=0 ; i<nums.size()-1 ; i++)
        {
            if (nums.at(i) >= nums.at(i+1))
            {
                break;
            }
            count++;
        }
        return count;
    }
};
