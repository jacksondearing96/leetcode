class Solution {
public:
    
    static constexpr bool ERROR = false; 
    static constexpr bool SUCCESS = true;
    
    class Range {
        int start;
        int end;
        bool initialised = false; 
        
        public:
        Range() {}
        
        Range(int element) {
            Initialise(element);
        }
        
        void Initialise(int element) {
            start = element;
            end = element;
            initialised = true;
        }
        
        bool Add(int element) {
            if (initialised) {
                if (element != end + 1) return ERROR; 
                end = element;
            } else {
                Initialise(element);
            }
            return SUCCESS;
        }
        
        string getString() {
            string start_str = to_string(start);
            if (start == end) return start_str;
            return start_str + "->" + to_string(end);
        }
    };
    
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        
        vector<string> ranges;
        Range range;
       
        for (int num : nums) {
            if (range.Add(num) == SUCCESS) continue;
            ranges.push_back(range.getString());
            range = Range(num);
        }
        
        ranges.push_back(range.getString());
       
        return ranges;
    }
};
