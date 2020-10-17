class Solution {
public:
    bool isTopOfMountain(int left, int middle, int right)
    {
        return left < middle && middle > right;
    }
    
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0;
        int end = A.size() - 1;
        
        while (true) {
            int middle = start + (end - start) / 2;
            int left = middle - 1;
            int right = middle + 1;
            
            if (isTopOfMountain(A[left], A[middle], A[right])) 
                return middle;
            
            if (A[middle] > A[left]) {
                // left side of mountain.
                start = middle;
            } else if (A[middle] < A[left]) {
                // right side of mountain.
                end = middle;
            }
        }
    }
};
