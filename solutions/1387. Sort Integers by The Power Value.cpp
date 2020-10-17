class Solution {
public:
​
    struct Power {
        int val;
        int power;
    };
    
    vector<int> generateRange(int lo, int hi) {
        vector<int> range;
        for (int i = lo; i <= hi; ++i) range.push_back(i);
        return range;
    }
    
    static Power getValPowerPair(int val) {
        int power = 0;
        int original_val = val;
        while (val != 1) {
            if (val % 2 == 0) {
                val /= 2;
            } else {
                val = (3 * val) + 1;
            }
            ++power;
        }
        Power p;
        p.val = original_val;
        p.power = power;
        return p;
    }
​
    struct less_than_key
    {
        inline bool operator() (const Power& struct1, const Power& struct2)
        {
            if (struct1.power != struct2.power) return struct1.power < struct2.power;
            return struct1.val < struct2.val;
        }
    };
    
    int getKth(int lo, int hi, int k) {
        vector<int> range = generateRange(lo, hi);
        vector<Power> powers;
