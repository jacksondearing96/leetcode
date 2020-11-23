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
    ListNode* middleNode(ListNode* head) {
        ListNode* runner = head;
        ListNode* walker = head;
        
        while (runner != nullptr) {
            runner = runner->next;
            if (runner == nullptr) break;
            walker = walker->next;
            runner = runner->next;
        }
        
        return walker;
    }
};
