/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> um;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
       if (um.find(node) != um.end())
        return um[node];
       um[node] = new Node(node->val);
       Node *new_node = um[node];
       new_node->neighbors.resize(node->neighbors.size(), nullptr);
       for (int i = 0; i < node->neighbors.size(); ++i) {
        new_node->neighbors[i] = cloneGraph(node->neighbors[i]);
       }
       return new_node;
    }
};
