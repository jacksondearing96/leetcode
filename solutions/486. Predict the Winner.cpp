class Solution {
public:
    
    bool PredictTheWinnerHelper(const vector<int>& nums, 
                                int start, 
                                int end, 
                                bool turn = true, 
                                int p1_score = 0, 
                                int p2_score = 0) {
        
        if (start > end) return p1_score >= p2_score; 
        
        if (turn) {
            return PredictTheWinnerHelper(nums, start + 1, end, !turn, p1_score + nums[start], p2_score) 
                || PredictTheWinnerHelper(nums, start, end - 1, !turn, p1_score + nums[end], p2_score); 
        } else {
            return PredictTheWinnerHelper(nums, start + 1, end, !turn, p1_score, p2_score + nums[start])
                && PredictTheWinnerHelper(nums, start, end - 1, !turn, p1_score, p2_score + nums[end]);
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return PredictTheWinnerHelper(nums, 0, nums.size() - 1); 
    }
};
