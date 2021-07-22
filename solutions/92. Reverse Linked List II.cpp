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
    void print(ListNode* head) {
        if (head == nullptr) {
            cout << endl;
            return;
        }
        cout << head->val << ",";
        print(head->next);
    }
    
    ListNode* reverse(ListNode* head, ListNode* prev = nullptr) {
        if (head == nullptr) return prev;
        ListNode* next = head->next;
        head->next = prev;
        return reverse(next, head);
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return nullptr;
        
        ListNode* tail = head;
        ListNode* prevToTail = nullptr;
        while (right != 0) {
            prevToTail = tail;
            tail = tail->next;
            --right;
        }
        
        ListNode* leftStart = head;
        ListNode* prevToLeftStart = nullptr;
        while(left != 1) {
            prevToLeftStart = leftStart;
            leftStart = leftStart->next;
            --left;
        }
        
        prevToTail->next = nullptr;
        if (prevToLeftStart == nullptr) {
            head = reverse(leftStart);
        } else {
            prevToLeftStart->next = reverse(leftStart);
        }
        leftStart->next = tail;
        
        return head;
    }
};
