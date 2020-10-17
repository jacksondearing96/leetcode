class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_set;
        for (int num : nums1) nums1_set.insert(num);
        
        unordered_set<int> intersection_set;        
        vector<int> intersection;
        
        for (int num : nums2) {
            if (nums1_set.find(num) != nums1_set.end()) {
                if (intersection_set.find(num) == intersection_set.end()) {
                    intersection.push_back(num);
                    intersection_set.insert(num);
                }
            }
        }
        return intersection;
    }
};
