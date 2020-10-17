class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        
        int closestSum = nums[0] + nums[1] + nums[2];
        int closestDifference = abs(target - closestSum);
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                for (int k = 0; k < nums.size(); ++k) {
                    if (i == k || j == k) continue;
                    int sum = nums[i] + nums[j] + nums[k];
                    int difference = abs(target - sum);
                    if (difference < closestDifference) {
                        closestSum = sum;
                        closestDifference = difference;
                    }
                    if (difference == 0) return sum;
                }
            }
        }        
       
        return closestSum;
    }
};
