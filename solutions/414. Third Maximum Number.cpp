class Solution {
public:
    void UpdateMaxNums(list<int>& max_nums, int num) {
        for (list<int>::iterator it = max_nums.begin();  
             it != max_nums.end();
             ++it) {
            if (num == *it) return;
            
            if (num > *it) {
                max_nums.insert(it, num);
                if (max_nums.size() > 3) max_nums.pop_back();
                return;
            }
        }
        if (max_nums.size() < 3) max_nums.push_back(num);
        
    }
    
    int thirdMax(vector<int>& nums) {
        
        list<int> max_nums;
        
        for (int num : nums) {
            UpdateMaxNums(max_nums, num);
        }
        
        if (max_nums.size() < 3) return max_nums.front();
        return max_nums.back();
    }
};
