/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
​
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) return root; 
        if (p->val < root->val && q->val > root->val) return root;
        if (p->val > root->val && q->val < root->val) return root;
        return lowestCommonAncestor((p->val < root->val) ? root->left : root->right, p, q);
    }
};
