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
TreeNode* buildTree(int preStart, int preEnd, int postStart, vector<int>& preorder,  
                                                            unordered_map<int, int> postIndex)
{
    if(preStart > preEnd) return NULL;
    if(preStart == preEnd) return new TreeNode(preorder[preStart]);

    int leftSubTreeStart = preStart+1;
     int leftSubTreeSize = postIndex[preorder[leftSubTreeStart]] - postStart + 1;
    TreeNode* root = new TreeNode(preorder[preStart]);
    
    root->left = buildTree(preStart+1 ,preStart+leftSubTreeSize, postStart, preorder ,postIndex);
    // root ->right = buildTree(preStart+leftSubTreeSize+1,preEnd ,postStart+leftSubTreeSize,postorder,postIndex);
    root->right = buildTree(preStart + leftSubTreeSize + 1, preEnd, 
                            postStart + leftSubTreeSize, preorder, postIndex);
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        unordered_map<int,int>postIndex;
        for(int i=0; i<postorder.size(); i++)
        {
            postIndex[postorder[i]] = i; // This Will store all the Index Of PostOrder Index
        }
        return buildTree(0,preorder.size()-1, 0, preorder, postIndex);
    }
};