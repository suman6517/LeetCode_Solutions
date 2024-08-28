/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markParents(TreeNode* root, unordered_map<TreeNode* , TreeNode*>&parents)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        if(temp ->left)
        {
            parents[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp ->right)
        {
            parents[temp->right] = temp;
            q.push(temp->right);
        }
    }

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*>parents;
        markParents(root , parents);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;

        while(!q.empty())
        {
            int size = q.size();
            if(curr_level ++ ==k) break;
            for(int i=0; i<size; i++)
            {
                TreeNode* current = q.front();
            q.pop();
            if(current ->left && !visited[current->left])
            {
                q.push(current ->left);
                visited[current->left] = true;
            }
            if(current ->right && !visited[current->right])
            {
                q.push(current ->right);
                visited[current->right] = true;
            }
            if(parents[current] && !visited[parents[current]])
            {
                q.push(parents[current]);
                visited[parents[current]] =true;
            }

            }

        }
        vector<int>res;
        while(!q.empty())
        {
            TreeNode* temp = q.front(); 
            q.pop();
            res.push_back(temp->val);
        }

        return res;
    }
};