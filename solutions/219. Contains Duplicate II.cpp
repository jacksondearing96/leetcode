class Solution {
public: 
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> num_and_indexes;
        for (int i = 0; i < nums.size(); ++i) {
            num_and_indexes.push_back(pair<int, int>(nums[i], i));
        }
        
        sort(num_and_indexes.begin(), num_and_indexes.end(), [](const pair<int, int>& p1,
                                                                const pair<int, int>& p2) {
            return p1.first < p2.first; 
        });
       
        for (int i = 1; i < nums.size(); ++i) {
            if (num_and_indexes[i].first == num_and_indexes[i - 1].first &&
                abs(num_and_indexes[i].second - num_and_indexes[i - 1].second) <= k) return true;
        }
        return false;
    }
};
