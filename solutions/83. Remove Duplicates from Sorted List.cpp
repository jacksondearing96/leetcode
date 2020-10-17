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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == NULL)
            return head;
        
        ListNode* iterator = head;
        ListNode* output = new ListNode(0);
        ListNode* outputHead = output;
        
        bool first = true;
        
        while (iterator != NULL)
        {
            
            if (first)
            {
                output->val = iterator->val;
                first = false;
            }
            else if (iterator->val != output->val)
            {
                output->next = new ListNode(0);
                output = output->next;
                output->val = iterator->val;
            }
            iterator = iterator->next;
        }
        return outputHead;
    }
};
