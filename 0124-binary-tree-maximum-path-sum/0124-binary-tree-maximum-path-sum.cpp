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

int getHeight(TreeNode* root , int &maximum)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = max(0, getHeight(root->left, maximum));
    int rightHeight =  max(0,getHeight(root ->right , maximum));
    maximum =  max(maximum , leftHeight+rightHeight+root->val);
    return max(leftHeight , rightHeight)+root->val;

}
    int maxPathSum(TreeNode* root) 
    {
        int max = INT_MIN;
        getHeight(root , max);
        return max;
        
    }
};