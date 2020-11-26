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
    
    void identifyDuplicates(ListNode* node, ListNode* prev, unordered_set<int>& duplicates) {
        if (node == nullptr) return;
        
        if (prev != nullptr && node->val == prev->val) {
            duplicates.insert(node->val);
        }
        identifyDuplicates(node->next, node, duplicates);
    }
    
    ListNode* Delete(ListNode* head, ListNode* node, ListNode* prev) {
        if (node == head) {
            ListNode* next = head->next;
            return next;
        }
        prev->next = node->next;
        return head;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> duplicates;
        identifyDuplicates(head, nullptr, duplicates);
        
        ListNode* node = head;
        ListNode* prev = nullptr;
        while (node != nullptr) {
            if (duplicates.find(node->val) != duplicates.end()) {
                head = Delete(head, node, prev);
            } else {
                prev = node;
            }
            node = node->next;
        }
        return head;
    }
};
