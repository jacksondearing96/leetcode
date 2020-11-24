class Solution {
public:
    enum Trend {
        DECREASING = 0,
        INCREASING = 1,
        EQUAL = 2,
        UNDETERMINED = 3
    };
    
    Trend DetermineTrend(int val1, int val2) {
        if (val1 == val2) return Trend::EQUAL;
        if (val1 > val2) return Trend::INCREASING;
        return Trend::DECREASING;
    }
    
    bool isMonotonicHelper(const vector<int>& arr, int index = 0, Trend trend = Trend::UNDETERMINED) {
        if (index >= arr.size()) return true;
        if (index == 0) return isMonotonicHelper(arr, index + 1, trend);
        
        Trend this_trend = DetermineTrend(arr[index - 1], arr[index]);
​
        if (this_trend == Trend::EQUAL) return isMonotonicHelper(arr, index + 1, trend);
        if (trend == Trend::UNDETERMINED) return isMonotonicHelper(arr, index + 1, this_trend);
        if (this_trend != trend) return false;
        
        return isMonotonicHelper(arr, index + 1, trend);
    }
    
    bool isMonotonic(vector<int>& A) {
        return isMonotonicHelper(A);
    }
};
