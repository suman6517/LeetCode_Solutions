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
void swapNode(TreeNode* leftNode , TreeNode* rightNode , TreeNode* root)
{
    if(leftNode == NULL && rightNode ==NULL)
    {
        return;
    }
    root -> left = rightNode;
    root -> right = leftNode;
    TreeNode* left = root -> left;
    TreeNode* right = root -> right;
    if(left != NULL)
    {
        swapNode(left -> left , left-> right  , left);
    }
    if(right != NULL)
    {
        swapNode(right -> left , right->right , right);
    }
   
}

public:
    TreeNode* invertTree(TreeNode* root) 
    {
     if(root == NULL)
     {
        return root;
     }
    swapNode(root ->left , root -> right , root);
    return root;
    }
};