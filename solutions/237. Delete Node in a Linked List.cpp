/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        
        if (node->next->next == nullptr) {
            ListNode* lastNode = node->next;
            node->next = nullptr;
            delete lastNode;
            return;
        }
        
        return deleteNode(node->next);
    }
};
