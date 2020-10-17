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
    
    void Visit(TreeNode* node, int depth, unordered_map<int, int>& right_side_view) {
        if (node == nullptr) return;
        
        Visit(node->left, depth + 1, right_side_view);
        right_side_view[depth] = node->val;
        Visit(node->right, depth + 1, right_side_view);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int, int> right_side_view;
        int depth = 0;
        Visit(root, depth, right_side_view);
                
        vector<int> solution;
        while (right_side_view.find(depth) != right_side_view.end()) {
            solution.push_back(right_side_view[depth]);
            ++depth;
        }
        return solution;
    }
};
