/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
​
class Solution {
public:
    
    ListNode* ReverseNode(ListNode* node, ListNode* prev)
    {
        if (node == nullptr)
        {
            return prev;
        }
        
        ListNode* next = node->next;
        node->next = prev;
        return ReverseNode(next, node);
    }
    
    ListNode* reverseList(ListNode* head) 
    {
        return ReverseNode(head, nullptr);
    }
};
