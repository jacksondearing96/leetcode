class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (duration == 0) return 0;
        
        return helper(timeSeries, duration, 0);
    }
    
    int helper(const vector<int>& series, int duration, int index) {
        // Finished.
        if (index == series.size()) return 0;
        
        if (index == series.size() - 1) return duration;
        
        int differenceToNext = series[index + 1] - series[index];
        int effectiveDuration = duration;
        
        if (differenceToNext < duration) effectiveDuration = differenceToNext;
        
        return effectiveDuration + helper(series, duration, index + 1);
    }
};
