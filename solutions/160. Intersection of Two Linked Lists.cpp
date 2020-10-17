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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if (headA == headB) return headA;
        
         unordered_set<ListNode*> observed;
        
         while (headA != nullptr || headB != nullptr) {
             
             if (observed.find(headA) != observed.end()) return headA;
             if (headA != nullptr) observed.insert(headA);
             if (headA != nullptr) headA = headA->next;
             
             if (observed.find(headB) != observed.end()) return headB;
             if (headB != nullptr) observed.insert(headB); 
             if (headB != nullptr) headB = headB->next;
         }
         return nullptr;
    }
};
