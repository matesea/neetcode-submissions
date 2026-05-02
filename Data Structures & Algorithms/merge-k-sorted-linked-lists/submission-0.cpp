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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode *a, const ListNode *b) -> bool {
            return a->val > b->val;
        };
       priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp); 
       for (auto& p: lists) {
        pq.push(p);
       }
       ListNode dummy;
       ListNode *p = &dummy;
       while (pq.size()) {
        ListNode *t = pq.top();
        pq.pop();
        p->next = new ListNode(t->val);
        p = p->next;
        if (t->next) {
            pq.push(t->next);
        }
       }
       return dummy.next;
    }
};
