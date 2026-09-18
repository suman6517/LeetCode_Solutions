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
bool isSameTree(TreeNode* leftNode , TreeNode* rightNode)
{
    if(leftNode == NULL && rightNode ==NULL)
    {
        return true;
    }
    if(leftNode == NULL || rightNode ==NULL)
    {
        return false;
    }
    return(leftNode -> val == rightNode->val) &&
        isSameTree(leftNode -> left , rightNode -> right) &&
        isSameTree(leftNode->right , rightNode->left);
}
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
        {
            return true;
        }

        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        return isSameTree(left , right);
    }
};