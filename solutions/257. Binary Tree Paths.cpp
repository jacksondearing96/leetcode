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
    
    void binaryTreePathsHelper(TreeNode* node, vector<int>& current, vector<vector<int>>& output) {
        if (node == nullptr) return;
                
        current.push_back(node->val);
​
        if (node->left != nullptr) binaryTreePathsHelper(node->left, current, output);
        if (node->right != nullptr) binaryTreePathsHelper(node->right, current, output);
        if (node->left == nullptr && node->right == nullptr) output.push_back(current);
        
        current.pop_back();
    }
    
    static string convert(const vector<int> path) {
        string output;
        bool first = true;
        for (int val : path) {
            if (!first) output += "->";
            output += to_string(val);
            first = false;
        }
        return output;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> paths;
        vector<int> current;
        
        binaryTreePathsHelper(root, current, paths);
        
