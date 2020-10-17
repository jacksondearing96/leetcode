class Solution {
public:
    
    int Area(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) * min(y1, y2);
    }
    
    bool LeftLineIsLimiting(int leftIndex, int rightIndex, const vector<int>& heights) {
        return heights[leftIndex] < heights[rightIndex];
    }
    
    int maxArea(vector<int>& heights) {
        
        int leftIndex = 0;
        int rightIndex = heights.size() - 1;
        
        int maxArea = 0;
        
        while (leftIndex < rightIndex)  {
                                    
            int area = Area(leftIndex, heights[leftIndex], rightIndex, heights[rightIndex]);
            if (area > maxArea) maxArea = area;
            
            LeftLineIsLimiting(leftIndex, rightIndex, heights) ? ++leftIndex : --rightIndex;
​
        }
        
        return maxArea;
    }
};
