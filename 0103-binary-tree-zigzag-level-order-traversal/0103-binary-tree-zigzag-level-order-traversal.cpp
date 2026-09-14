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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;

        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode*> qu;

        qu.push(root);
        bool flagForRotate = false;

        while(!qu.empty())
        {
            vector<int>currLevel;
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

               currLevel.push_back(temp ->val);
            }

            if(flagForRotate)
            {
                reverse(currLevel.begin() , currLevel.end());
            }
            ans.push_back(currLevel);
            flagForRotate = !flagForRotate;
        }

        return ans;
    }
};