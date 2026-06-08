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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
       ListNode dummy(0, head); 
       ListNode *p = &dummy;
       ListNode *prev = nullptr;
       right = right - left + 1;
       ListNode *first;
       while (left-- > 0) {
        prev = p;
        p = p->next;
        first = p;
       }
       ListNode *pprev = nullptr;
       ListNode *next;
       while (right-- > 0) {
        next = p->next;
        p->next = pprev;
        pprev = p;
        p = next;
       }
       prev->next = pprev;
       first->next = p;
       return dummy.next;
    }
};