class Solution {
public:
    bool IsEven(int num) {
        return num % 2 == 0;
    }
    
    int SumOfEvens(const vector<int>& nums)
    {
        int result = 0;
        for (int num : nums)
            if (IsEven(num)) result += num;
        return result;
    }
    
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int result = SumOfEvens(A);
        vector<int> results;
        
        for (auto query : queries)
        {
            int val = query[0];
            int index = query[1];
            int temp = A[index];
            A[index] = A[index] + val;
            
            if (IsEven(temp))
            {
                if (IsEven(A[index]))
                {
                    result += val;
                }
                else
                {
                    result -= temp;
                }
            }
            else
            {
                if (IsEven(A[index]))
                {
                    result += A[index];
                }
            }
            results.push_back(result);
        }
        return results;
