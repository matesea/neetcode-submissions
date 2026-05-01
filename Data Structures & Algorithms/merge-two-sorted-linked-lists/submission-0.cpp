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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode dummy; 
       ListNode *p = &dummy;
       ListNode *tmp = list1;
       while (list1 || list2) {
        if (!list2 || (list1 && list2 && list1->val < list2->val)) {
            tmp = list1;
            p->next = list1;
            list1 = list1->next;
            p = tmp;
            p->next = nullptr;
        } else {
            tmp = list2;
            p->next = list2;
            list2 = list2->next;
            p = tmp;
            p->next = nullptr;
        }
       }
       return dummy.next;
    }
};
