/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string res;
       queue<TreeNode*> q;
       q.push(root); 
       while (q.size() > 0) {
        TreeNode *t = q.front();
        q.pop();
        if (!t) {
            res += "N,";
        } else {
            res += to_string(t->val) + ",";
            q.push(t->left);
            q.push(t->right);
        }
       }
       return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "N") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        queue<TreeNode *> q;
        q.push(root);

        while (getline(ss, val, ',')) {
            TreeNode *t = q.front();
            q.pop();
            if (val != "N") {
                t->left = new TreeNode(stoi(val));
                q.push(t->left);
            }
            getline(ss, val, ',');
            if (val != "N") {
                t->right = new TreeNode(stoi(val));
                q.push(t->right);
            }
        }
        return root;
    }
};
