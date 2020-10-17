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
    
    // postorder - children come before parents.
    // inorder - left children left, right children right
    
    TreeNode* buildTree(vector<int>::iterator in_order_begin, 
                        vector<int>::iterator in_order_end, 
                        vector<int>::iterator post_order_begin,
                        vector<int>::iterator post_order_end) {
        if ((in_order_begin == in_order_end) || (post_order_begin == post_order_end)) return nullptr;
        
        int insert_val = *(post_order_end - 1);
        
        auto found = find(in_order_begin, in_order_end, insert_val);
        if (found == in_order_end) return buildTree(in_order_begin, in_order_end, post_order_begin, post_order_end - 1); 
       
        TreeNode* root = new TreeNode(insert_val);
        root->left = buildTree(in_order_begin, found, post_order_begin, post_order_end - 1);
        root->right = buildTree(found + 1, in_order_end, post_order_begin, post_order_end - 1);
        
        return root;
    }
   
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
