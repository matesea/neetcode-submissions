/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* p = head;
        Node* q;
        while (p) {
            q = new Node(p->val);
            q->next = p->random;
            p->random = q;
            p = p->next;
        }
        p = head;
        while (p) {
            q = p->random;
            q->random = q->next ? q->next->random : nullptr;
            p = p->next;
        }
        p = head;
        Node *res = head->random;
        while (p) {
            q = p->random;
            p->random = q->next;
            q->next = p->next ? p->next->random : nullptr;
            p = p->next;
        }
        return res;
    }
};
