class Solution {
public:
    int findContentChildren(vector<int>& greed_factors, vector<int>& cookie_sizes) {
        sort(greed_factors.begin(), greed_factors.end());
        sort(cookie_sizes.begin(), cookie_sizes.end());
        
        vector<int>::iterator greed = greed_factors.begin();
        vector<int>::iterator cookie = cookie_sizes.begin();
        
        int content_children = 0;
        while (greed != greed_factors.end() &&
               cookie != cookie_sizes.end()) {
            
            if (*cookie >= *greed) {
                ++content_children;
                ++greed;
            }
            ++cookie;
        }
        return content_children;
    }
};
