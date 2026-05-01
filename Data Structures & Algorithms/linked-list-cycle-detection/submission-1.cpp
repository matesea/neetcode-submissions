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
    bool hasCycle(ListNode* head) {
        ListNode *p  = head, *fast = head;
        if (!p) return false;
        p = p->next;
        if (!p) return false;
        fast = p->next;
        while (p && fast && p != fast) {
            p = p->next;
            fast = fast->next;
            if (!fast) break;
            fast = fast->next;
        }
        if (p == nullptr || fast == nullptr)
            return false;
        return p == fast;
    }
};
