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
    
    bool isLeaf(TreeNode* node) {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }
    
    void pathSum(TreeNode* node, int sum, vector<int>& current, vector<vector<int>>& solutions) {
        if (node == nullptr) return;
        
        sum -= node->val;
        current.push_back(node->val);
        
        if (isLeaf(node) && sum == 0) solutions.push_back(current);
       
        pathSum(node->left, sum, current, solutions);
        pathSum(node->right, sum, current, solutions);
        
        current.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> current;
        vector<vector<int>> solutions;
        pathSum(root, sum, current, solutions);
        return solutions;
    }
};
