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

int height(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int LeftHeight = height(root ->left);
    if(LeftHeight == -1)
    {
        return -1;
    }
    int RightHeight = height(root ->right);
    if(RightHeight ==-1)
    {
        return -1;
    }

    if(abs(RightHeight - LeftHeight) >1)
    {
        return -1;
    }
    return 1+(max(LeftHeight , RightHeight));
    
}
public:
    bool isBalanced(TreeNode* root) 
    {
        return height(root) !=-1;
    }
};