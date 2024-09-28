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
TreeNode* build(vector<int>& preorder , int &index , int bound)
{
    if( index == preorder.size() || preorder[index] >bound)
    {
        return NULL;
    }
    TreeNode* node =  new TreeNode(preorder[index++]);
    node ->left =build(preorder , index , node->val);
    node ->right = build(preorder , index , bound);

    return node;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i =0;
        return build(preorder , i,INT_MAX);
    }
};