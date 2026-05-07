class WordDictionary {
    struct node {
        unordered_map<char,node*> children;
        bool finish;
    };
    node head;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        node *p = &head;
        for (const auto& c: word) {
            if (p->children.find(c) == p->children.end())
                p->children[c] = new node();
            p = p->children[c];
        }
        p->finish = true;
    }
    
    bool search(string& word) {
        return search(word, 0, &head);
    }
    bool search(string& word, int i, node *p) {
        if (i == word.size())
            return p && p->finish;
        else if (word[i] == '.') {
            for (auto& [c, next]: p->children) {
                if (search(word, i + 1, next))
                    return true;
            }
            return false;
        }
        auto& np = p->children;
        if (np.find(word[i]) == np.end()) return false;
        return search(word, i + 1, np[word[i]]);
    }
};
