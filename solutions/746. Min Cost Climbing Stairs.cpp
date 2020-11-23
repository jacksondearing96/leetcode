class Solution {
public:
    
    unordered_map<int, int> step_costs;
    
    int minCostClimbingStairsHelper(const vector<int>& costs, int step) {
        if (step >= costs.size()) return 0;
        
        if (step_costs.find(step) != step_costs.end()) return step_costs[step];
        
        int cost = costs[step] + min(minCostClimbingStairsHelper(costs, step + 1),
                                 minCostClimbingStairsHelper(costs, step + 2));
        step_costs[step] = cost;
        return cost;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min(minCostClimbingStairsHelper(cost, 0),
                   minCostClimbingStairsHelper(cost, 1));
    }
};
