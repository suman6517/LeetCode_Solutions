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
int height(TreeNode* root , int &diameter )
{
    if(root == NULL)
    {
        return 0;
    }
    int LeftHeight = height(root ->left , diameter);
    int RightHeight = height(root ->right , diameter);
    diameter = max(diameter , LeftHeight+RightHeight);
    return 1+(max(LeftHeight , RightHeight));
    
}
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        height(root , diameter);
        return diameter;
        
    }
};