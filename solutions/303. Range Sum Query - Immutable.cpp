class NumArray {
public:
    
    vector<int> end_sums;
    int size = 0;
    
    NumArray(vector<int>& nums) {
       size = nums.size();
       populateEndSums(nums); 
    }
    
    void populateEndSums(vector<int>& nums) {
        if (nums.empty()) return;
        endSum(nums, 0);
        reverse(end_sums.begin(), end_sums.end());
    }
    
    int endSum(const vector<int>& nums, int i) {
        int sum = nums[i];
        if (i != nums.size() - 1) sum += endSum(nums, i + 1);
        end_sums.push_back(sum);
        return sum;
    }
    
    int sumRange(int i, int j) {
        if (size == 0) return 0;
        int sum = end_sums[i];
        return (j == size - 1) ? sum : sum -= end_sums[j + 1];
    }
};
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
