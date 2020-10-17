class Solution {
public:
    
    vector<int> store = { 1 };
    
    int numTrees(int n) {
        if (store.size() > n) return store[n];
        
        int structures = 0;
        for (int i = 0; i < n; ++i) {
            structures += numTrees(i) * numTrees(n - i - 1);
        }
        store.push_back(structures);
        return structures;
    }
};
