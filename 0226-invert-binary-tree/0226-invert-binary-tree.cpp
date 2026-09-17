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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
        {
            return root;
        }

        queue<TreeNode*>qu;
        qu.push(root);

        while(!qu.empty())
        {
            int size = qu.size();
            TreeNode* temp = NULL;

            for(int i =0; i< size; i++)
            {
                TreeNode* node = qu.front();
                qu.pop();

                if(node -> left != NULL && node-> right != NULL)
                {
                    temp = node -> right;
                    node -> right = node ->left;
                    node -> left = temp;

                    qu.push(node ->left);
                    qu.push(node -> right);
                }
                else if( node -> left != NULL && node -> right == NULL)
                {
                    node -> right = node -> left;
                    node -> left = NULL;
                    qu.push(node -> right);
                }
                else if(node -> right != NULL && node ->left == NULL)
                {
                    node -> left = node ->right;
                    node -> right = NULL;
                    qu.push(node -> left);
                }
            }
        }

        return root;
    }
};