class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int max = nums[0];
        int second_max = -1;
        int max_index = 0;
        
        for (int index = 1; index < nums.size(); ++index) {
            int num = nums[index];
           if (num > max) {
                second_max = max;
                max = num;
                max_index = index;
            } else if (num > second_max) {
               second_max = num;
           }
        }
        cout << max << endl;
        cout << second_max << endl;
        
        return (max >= 2 * second_max) ? max_index : -1;
    }
};
