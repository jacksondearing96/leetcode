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
    
    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
                return root;
            }
            insert(root->left, val);
        } else if (val > root->val) {
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
                return root;
            }
            insert(root->right, val);
        }
        
        return root;
    }
    
    TreeNode* binarySearch(const vector<int>& nums, int start, int end, TreeNode* root) {
        if (start > end) return root;
                
        int middle = start + ((end - start) / 2);
        root = insert(root, nums[middle]);
        
        binarySearch(nums, start, middle - 1, root);
