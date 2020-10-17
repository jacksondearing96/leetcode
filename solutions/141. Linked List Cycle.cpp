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
    bool hasCycle(ListNode* head) 
    {
        if (head == NULL || head->next == NULL)
            return false;
        
        ListNode* walker = head;
        ListNode* runner = head->next;
        
        while (runner->next != NULL)
        {
            runner = runner->next;
            if (runner == NULL)
                return false;
            
            runner = runner->next;
            if (runner == NULL)
                return false;
            
            walker = walker->next;
            
            if (runner == walker)
            {
                return true;
            }
        }
        return false;
    }
};
