class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    
    void sortColors(vector<int>& nums) {
        int next_0_pos = 0;
        int next_2_pos = nums.size() - 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i > next_2_pos) return;
            if (i < next_0_pos) continue; 
            
            switch (nums[i]) {
                case 0:
                    swap(nums, next_0_pos, i);
                    ++next_0_pos;
                    break;
                case 1:
                    continue;
                case 2:
                    swap(nums, next_2_pos, i);
                    --next_2_pos;
                    break;
            }
            --i;
        } 
    }
};
