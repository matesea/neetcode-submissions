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
       Node *p = head; 
       Node *res = nullptr;
       if (!head) return head;
       while (p) {
        Node *q = new Node(p->val);
        q->random = p->random;
        p->random = q;
        p = p->next;
       }
       p = head;
       while (p) {
        Node *q = p->random;
        q->next = p->next ? p->next->random : nullptr;
        q->random = q->random ? q->random->random : nullptr;
        p = p->next;
       }
       res = head->random;
       p = head;
       while (p) {
        p->random = p->random->random;
        p = p->next;
       }
       return res;
    }
};
