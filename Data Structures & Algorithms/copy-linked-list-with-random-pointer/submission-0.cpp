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
       unordered_map<Node*,Node*> umap;
       if (!head) return head;
       Node *p = head;
       Node dummy(0), *q = &dummy;
       while (p) {
        q->next = new Node(p->val);
        q->next->random = p->random;
        umap[p] = q->next;
        q = q->next;
        p = p->next;
       }
       q = dummy.next;
       while (q) {
        q->random = umap[q->random];
        q = q->next;
       }
       return dummy.next;
    }
};
