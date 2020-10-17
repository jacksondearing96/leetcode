/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    ListNode* SplitMiddle(ListNode* head) {
        ListNode* walker = head;
        ListNode* prev_walker = nullptr;
        ListNode* runner = head;
        
        while (true) {
            if (runner == nullptr) break;
            runner = runner->next;
            if (runner == nullptr) break;
            runner = runner->next;
            prev_walker = walker;
            walker = walker->next;
        }
        
        if (prev_walker != nullptr) prev_walker->next = nullptr;
        return walker;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
