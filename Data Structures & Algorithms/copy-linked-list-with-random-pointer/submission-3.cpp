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
        unordered_map<Node*,Node*> um;
        Node* p = head;
        while (p) {
            if (um.find(p) == um.end())
                um[p] = new Node(0);
            um[p]->val = p->val;
            if (p->next && um.find(p->next) == um.end())
                um[p->next] = new Node(0);
            if (p->random && um.find(p->random) == um.end())
                um[p->random] = new Node(0);
            um[p]->next = um[p->next];
            um[p]->random = um[p->random];
            p = p->next;
        }
        return um[head];
    }
};
