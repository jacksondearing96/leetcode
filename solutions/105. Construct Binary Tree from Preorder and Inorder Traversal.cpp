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
    
    TreeNode* buildTree(vector<int>::iterator preorder_begin,
                        vector<int>::iterator preorder_end,
                        vector<int>::iterator inorder_begin,
                        vector<int>::iterator inorder_end) {
        if (preorder_begin == preorder_end || inorder_begin == inorder_end) return nullptr;
        
        int insert_val = *preorder_begin;
        auto found = find(inorder_begin, inorder_end, insert_val);
        if (found == inorder_end) return buildTree(preorder_begin + 1, preorder_end, inorder_begin, inorder_end);
        
        TreeNode* root = new TreeNode(insert_val);
        root->left = buildTree(preorder_begin + 1, preorder_end, inorder_begin, found);
        root->right = buildTree(preorder_begin + 1, preorder_end, found + 1, inorder_end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
