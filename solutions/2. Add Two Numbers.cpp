/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int sum;
 *     ListNode *next;
 *     ListNode() : sum(0), next(nullptr) {}
 *     ListNode(int x) : sum(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : sum(x), next(next) {}
 * };
 */
class Solution {
public:
    
    static constexpr int BASE = 10;
    
    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 == nullptr && l2 == nullptr) {
            if (carry == 0) return nullptr; 
            return new ListNode(1);
        }
        
        int sum = 0;
        if (l1 != nullptr) sum += l1->val;
        if (l2 != nullptr) sum += l2->val;
        sum += carry;
       
        ListNode* node = new ListNode(sum % BASE);
        node->next = addTwoNumbersHelper((l1 == nullptr) ? nullptr : l1->next,
                                         (l2 == nullptr) ? nullptr : l2->next,
                                         sum / BASE);
        return node;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersHelper(l1, l2);
    }
};
