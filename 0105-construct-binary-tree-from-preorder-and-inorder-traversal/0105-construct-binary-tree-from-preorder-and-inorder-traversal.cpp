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
TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                        vector<int>& inorder, int inStart, int inEnd, 
                        map<int, int>& inMpp) {
        // Base Case
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // Create the root node
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the index of the root in the inorder traversal
        int inRoot = inMpp[root->val];
        int numsLeft = inRoot - inStart;

        // Recursively build the left and right subtrees
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, 
                               inorder, inStart, inRoot - 1, inMpp);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, 
                                inorder, inRoot + 1, inEnd, inMpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMpp;
        
        // Populate the map with inorder values and their indices
        for (int i = 0; i < inorder.size(); i++) {
            inMpp[inorder[i]] = i;
        }

        // Build the tree using the helper function
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, 
                                   inorder, 0, inorder.size() - 1, inMpp);

        return root;
    }
};