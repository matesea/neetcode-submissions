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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode dummy(0, head);
       ListNode *slow = &dummy, *fast = &dummy;
       while (n-- > 0) fast = fast->next;
       ListNode *prev = nullptr;
       while (fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
       }
       prev->next = prev->next->next;
       return dummy.next;
    }
};
