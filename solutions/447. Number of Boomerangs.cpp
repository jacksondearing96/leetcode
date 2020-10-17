class Solution {
public:
    
    double distance(const vector<int>& point1, const vector<int>& point2) {
        return sqrt(double(pow(point1[0] - point2[0], 2)) + double(pow(point1[1] - point2[1], 2))); 
    }
   
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int boomerangs = 0;
        
        for (int i = 0; i < points.size(); ++i) {
            vector<int>& middle_point = points[i];
           
            unordered_map<double, int> distance_frequencies;
​
            for (int j = 0; j < points.size(); ++j) {
                vector<int>& point = points[j];
                
                if (i == j) continue;
                double dist = distance(middle_point, point); 
                ++distance_frequencies[dist];
                boomerangs += distance_frequencies[dist] - 1; 
            } 
        }
        return boomerangs * 2;
    }
};
