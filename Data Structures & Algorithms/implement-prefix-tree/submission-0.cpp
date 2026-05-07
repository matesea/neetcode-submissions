class PrefixTree {
    struct TrieNode {
        vector<TrieNode*> v;
        bool finish;
         TrieNode() {
             finish = false;
             v.resize(26, nullptr);
         }
    };
    TrieNode head;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
       TrieNode *p = &head; 
       for (auto& c: word) {
        if (p->v[c - 'a'] == nullptr)
            p->v[c-'a'] = new TrieNode;
        p = p->v[c-'a'];
       }
       p->finish = true;
    }
    
    bool search(string word) {
       TrieNode *p = &head; 
       for (auto& c: word) {
        if (p->v[c - 'a'] == nullptr) return false;
        p = p->v[c-'a'];
       }
       return p->finish;
        
    }
    
    bool startsWith(string prefix) {
       TrieNode *p = &head; 
       for (auto& c: prefix) {
        if (p->v[c - 'a'] == nullptr) return false;
        p = p->v[c-'a'];
       }
       return true;
    }
};
