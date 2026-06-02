class Solution {
    struct trie_node {
        vector<trie_node*> children;
        int count;
        trie_node() {
            count = 0;
            children.resize(26, nullptr);
        }
    };
    trie_node root;
    void insert(string& s) {
        int i = 0;
        trie_node *p = &root;
        while (i < s.size()) {
            char c = s[i] - 'a';
            if (!p->children[c])
                p->children[c] = new trie_node();
            p = p->children[c];
            p->count++;
            ++i;
        }
    }
    string findLCP(int n) {
        string res;
        int i;
        trie_node *p = &root;
        while (p) {
            for (i = 0; i < 26; ++i) {
                if (p->children[i] && p->children[i]->count == n)
                    break;
            }
            // cout << "i=" << i << endl;
            if (i >= 26 || !p->children[i] || p->children[i]->count != n)
                break;
            res += 'a' + i;
            p = p->children[i];
        }
        return res;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (auto& s: strs)
            insert(s);
        return findLCP(strs.size());
    }
};