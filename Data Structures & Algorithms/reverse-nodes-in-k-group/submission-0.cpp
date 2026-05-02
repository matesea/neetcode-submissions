/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if (!head) return head;
       ListNode *p = head; 
       int count = 1;
       while (count < k && p) {
        p = p->next;
        count++;
       }
       if (!p) return head;
       p = p->next;
       ListNode *nextG = reverseKGroup(p, k);
       ListNode *q = head;
       ListNode *prev = nextG;
       while (q != p) {
        ListNode *next = q->next;
        q->next = prev;
        prev = q;
        q = next;
       }
       return prev;
    }
};
