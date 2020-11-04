class Solution {
public:
    
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> candy_types;
        for (int candy : candies) candy_types.insert(candy); 
        return min(candies.size() / 2, candy_types.size());
    }
};
