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
    vector<double> averageOfLevels(TreeNode* root) 
    {
         vector<double>ans;
        if(root -> right == NULL && root ->left == NULL)
        {
            ans.push_back(root -> val);
            return ans;
        }
        queue<TreeNode*>qu;
        qu.push(root);

        while(!qu.empty())
        {
            double total = 0;
            int size = qu.size();

            for(int i =0; i<size; i++)
            {
                TreeNode* node = qu.front();
                qu.pop();

                if(node->left != NULL)
                {
                    qu.push(node -> left);
                }
                if(node->right != NULL)
                {
                    qu.push(node -> right);
                }
                total += node ->val;
            }
            double avg = total /size;

            ans.push_back(avg);
        }

        return ans;
    }
};