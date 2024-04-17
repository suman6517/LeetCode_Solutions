class Solution {
public:
    string path;
    priority_queue<string, vector<string>, greater<string>>pq;
    void paths(TreeNode* root)
    {
        if(!root) return;

        char ch = root->val +'a';
        path.insert(path.begin(), ch);
        if(!root->left and !root->right) pq.push(path);
        
        paths(root->left);
        paths(root->right);

        path.erase(path.begin());
    }

    string smallestFromLeaf(TreeNode* root) 
    {
        paths(root);
        return pq.top();
    }
};