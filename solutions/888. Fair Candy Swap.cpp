class Solution {
public:
    
    int TotalCandy(const vector<int>& candies) {
        int total = 0; 
        for (int candy : candies) {
            total += candy;
        }
        return total;
    }
    
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int total_A = TotalCandy(A);
        int total_B = TotalCandy(B);
        
        const vector<int>& smaller_candies = (total_A > total_B) ? B : A;
        const vector<int>& larger_candies = (total_A > total_B) ? A : B;
        int difference = abs(total_A - total_B);
        
        unordered_set<int> smaller_candies_set;
        for (int candy : smaller_candies) {
            smaller_candies_set.insert(candy);
        }
       
        for (int candy : larger_candies) {
            int target_candy = candy - difference / 2;
            if (smaller_candies_set.find(target_candy) != smaller_candies_set.end()) {
                vector<int> swap = {candy, target_candy};
                if (total_B > total_A) reverse(swap.begin(), swap.end());
                return swap;
            }
        }
        
        return vector<int>();
    }
};
