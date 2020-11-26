class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> present = nums;
        for (int& i : present) i = 0;
        
        for (int num : nums) {
            if (present[num] == 1) return num;
            present[num] = 1;
        }
        
        return -1;
    }
};
