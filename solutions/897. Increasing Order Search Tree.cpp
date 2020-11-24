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
    
    void increasingBSTHelper(TreeNode* node, TreeNode** head, TreeNode** tail) {
        if (node == nullptr) return;
       
        increasingBSTHelper(node->left, head, tail);
​
        if (*head == nullptr && node->left == nullptr) *head = node;
        if (*tail != nullptr) (*tail)->right = node;
        node->left = nullptr;
        *tail = node;
        
        increasingBSTHelper(node->right, head, tail);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;
        increasingBSTHelper(root, &head, &tail);
        return head;
    }
};
