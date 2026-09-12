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
void TraversePost(TreeNode* root , vector<int>&postOrder)
{
    if(root == NULL)
    {
        return;
    }
    TraversePost(root -> left , postOrder);
    TraversePost(root->right ,postOrder);
    postOrder.push_back(root -> val);

}
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> postOrder;
        TraversePost(root, postOrder);
        return postOrder;
        
    }
};