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
        return node->left == nullptr && node->right == nullptr;
    }
    
    void sumNumbersHelper(TreeNode* node, int* total_sum, string current_num = "") {
        if (node == nullptr) return;
        
        current_num += to_string(node->val);
        if (isLeaf(node)) {
            *(total_sum) += stoi(current_num);
            return;
        }
        
        sumNumbersHelper(node->left, total_sum, current_num);
        sumNumbersHelper(node->right, total_sum, current_num);
    }
    
    int sumNumbers(TreeNode* root) {
        int total_sum = 0;
        sumNumbersHelper(root, &total_sum);
        return total_sum;
    }
};
