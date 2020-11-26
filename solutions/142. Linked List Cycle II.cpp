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
    
    ListNode* detectCycleHelper(ListNode* node, unordered_set<ListNode*>& seen) {
        if (node == nullptr) return nullptr;
        
        if (seen.find(node) != seen.end()) return node;
        seen.insert(node);
        return detectCycleHelper(node->next, seen);
    }
    
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        return detectCycleHelper(head, seen);
    }
};
