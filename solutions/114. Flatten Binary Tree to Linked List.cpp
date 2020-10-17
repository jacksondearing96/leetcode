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
    
    TreeNode* flatJoin(TreeNode* list1, TreeNode* list2) {
        if (list1 == nullptr) return list2;
        TreeNode* list1_start = list1;
        while (list1->right != nullptr) list1 = list1->right;
        list1->right = list2;
        return list1_start;
    }
   
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* left_tree = root->left;
        TreeNode* right_tree = root->right;
        
        root->left = nullptr;
        flatten(left_tree);
        flatten(right_tree);
        root->right = flatJoin(left_tree, right_tree);
    }
};
