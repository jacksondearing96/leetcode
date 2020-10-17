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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        ListNode* l3 = new ListNode(0);
        ListNode* l3Head = l3;
        
        bool l2Empty = false, l1Empty = false, first = true;
        
        if (l1 == NULL)
                l1Empty = true;
            
        if (l2 == NULL)
            l2Empty = true;
        
        while (true)
        {   
            
            if (l2Empty) {
                l3->val = l1->val;
                l1 = l1->next;
                
            } else if (l1Empty) {
                l3->val = l2->val;
                l2 = l2->next;
                
            } else if (l1->val < l2->val) {
                l3->val = l1->val;
                l1 = l1->next;
                
            } else {
                l3->val = l2->val;
                l2 = l2->next;
            }
            
