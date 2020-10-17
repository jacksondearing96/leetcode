/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    unordered_map<string, vector<TreeNode*>> solution_store;
    
    string GetKey(int start, int end) {
        return to_string(start) + "::" + to_string(end);
    }
    
    vector<TreeNode*> generateTrees(int start, int end) {
        string key = GetKey(start, end);
        if (solution_store.find(key) != solution_store.end()) {
            return solution_store[key];
        }
        
        vector<TreeNode*> trees;
        for (int i = start; i < end; ++i) {
            vector<TreeNode*> left_subtrees = generateTrees(start, i);
            vector<TreeNode*> right_subtrees = generateTrees(i + 1, end);
            
            for (auto left_subtree : left_subtrees) {
                for (auto right_subtree : right_subtrees) {
                    trees.push_back(new TreeNode(i + 1, left_subtree, right_subtree));
                }
            }
        }
        
        if (trees.empty()) trees = { nullptr };
        solution_store[key] = trees;
        return trees;
    }
    
