class Solution {
public:
    string countAndSay(int n) {
        
        string seq = "1";
        for (int i = 1; i < n; i++)
        {
            string next = "";
            int count = 1;
            for (int j = 0; j < seq.length(); j++)
            {
                if (j == seq.length() - 1)
                {
                    next += (to_string(count) + seq[j]);
                }
                else if (seq[j + 1] != seq[j])
                {
                    next += (to_string(count) + seq[j]);
                    count = 1;
                }
                else 
                {
                    count++;
                }
            }
            seq = next;
        }
        return seq;
        
    }
};
