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
TreeNode* buildTrees(vector<int>& inorder, int stInOrder , int endInOrder , 
                     vector<int>& postorder , int stPostOrder , int endPostOrder , map<int ,int>&mpp)
                     {
                        if(stInOrder > endInOrder || stPostOrder >endPostOrder)
                        {
                            return NULL;
                        }
                        TreeNode* root = new TreeNode(postorder[endPostOrder]);

                        int inRoot = mpp[postorder[endPostOrder]];
                        int numsLeft = inRoot - stInOrder;

                        root ->left = buildTrees(inorder , stInOrder , inRoot-1 , postorder , stPostOrder ,
                                       stPostOrder+numsLeft-1 , mpp);
                        root ->right = buildTrees(inorder , inRoot +1 ,endInOrder , postorder , stPostOrder
                                       +numsLeft  , endPostOrder-1, mpp);
                        return root;
                     }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size() != postorder.size())
        {
            return NULL;
        }
        map<int,int>mpp;
        for(int i =0 ; i<inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }
        return buildTrees(inorder , 0, inorder.size()-1 , postorder , 0 , postorder.size()-1 , mpp);
        
    }
};