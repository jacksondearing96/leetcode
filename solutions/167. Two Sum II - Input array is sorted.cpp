class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int last;
        for (int i=0 ; i<numbers.size()-1 ; i++)
        {
            if (i == 0 || numbers.at(i) != last)
            {
                for (int j=numbers.size()-1 ; j>i ; j--)
                {
                    if (numbers.at(i) + numbers.at(j) == target)
                    {
                        return {i+1, j+1};
                    }
                }
            }
            
            last = numbers.at(i);
        }
        
    }
};
