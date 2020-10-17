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
class Solution {
public:
    
    void insert(ListNode* node, ListNode* node_to_insert) {
        ListNode* temp = node->next;
        node->next = node_to_insert;
        node_to_insert->next = temp;
    }
    
    ListNode* removeAndReturnLastNodeInList(ListNode* head) {
        ListNode* node = head;
        ListNode* prev = head;
        while (node->next != nullptr) {
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        return node;
    }
    
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        
        ListNode* last = removeAndReturnLastNodeInList(head);
        insert(head, last);
        reorderList(head->next->next);
    }
};
