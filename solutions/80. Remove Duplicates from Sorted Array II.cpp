class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int current_num = nums[0];
        bool has_duplicate = false;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != current_num) {
                current_num = nums[i];
                has_duplicate = false;
            } else {
                if (has_duplicate) {
                    nums.erase(nums.begin() + i);
                    --i;
                } else {
                    has_duplicate = true;
                }
            }
        }
        return nums.size();
    }
};
