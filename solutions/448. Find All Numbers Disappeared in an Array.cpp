class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        if (nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        
        vector<int> missing;
        
        int start = 1;
        while (start != nums[0]) {
            missing.push_back(start);
            ++start;
        }
        
        int end = nums.size();
        while (end != nums[nums.size() - 1]) {
            missing.push_back(end);
            --end;
        }
        
        int prev = nums[0];
        for (int num : nums) {
            int diff = num - prev;
            while (diff > 1) {
                --diff;
                missing.push_back(prev + diff);
            }
            prev = num;
        }
        
        return missing;
    }
};
