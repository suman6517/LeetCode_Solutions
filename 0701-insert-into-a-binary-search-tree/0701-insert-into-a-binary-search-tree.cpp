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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL)
        {
            return new TreeNode(val);
        }
        TreeNode* current = root;
        while(true)
        {
            if(current ->right <=val)
            {
                if(current ->right != NULL)
                {
                    current = current ->right;
                }
                else
                {
                    current ->right =  new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(current ->left != NULL)
                {
                    current = current ->left;
                }
                else
                {
                    current->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};