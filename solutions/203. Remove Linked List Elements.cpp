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
    ListNode* removeElement(ListNode* prev, ListNode* node) {
        if (node == nullptr) return nullptr;
        
        if (prev == nullptr) {
            ListNode* next = node->next;
            delete node;
            return next;
        }
        
        prev->next = node->next;
        delete node;
        return prev->next;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* node = head;
        ListNode* prev = nullptr;
        
        bool isOperatingOnHead = true;
        
        while (node != nullptr) {
            if (node->val == val) {
                node = removeElement(prev, node);
                // prev remains the same.
                if (isOperatingOnHead) head = node;
            } else {
                prev = node;
                node = node->next;
                if (isOperatingOnHead) isOperatingOnHead = false;
            }
        }
        return head;
    }
};
