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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(root == NULL)
        {
            return ans;
        }
        queue<TreeNode*>qu;
        qu.push(root);

        while(! qu.empty())
        {
            vector<int>level;
            int size = qu.size();
            for(int i=0; i< size; i++)
            {
                TreeNode* temp = qu.front();
                qu.pop();

                if(temp -> left != NULL)
                {
                    qu.push(temp -> left);
                }
                if(temp -> right != NULL)
                {
                    qu.push(temp -> right);
                }

                level.push_back(temp -> val);
            }
            ans.push_back(level);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};