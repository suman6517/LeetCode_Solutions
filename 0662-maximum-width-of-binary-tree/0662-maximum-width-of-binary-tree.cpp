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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int ans =0;
        queue<pair<TreeNode* , long>>q;
        q.push({root ,0});

        while(!q.empty())
        {
            int size =q.size();
            int min = q.front().second;
            int first , last ;
            for (int i =0 ; i<size; i++)
            {
              int curr_id = q.front().second-min;
              TreeNode* temp = q.front().first;
              q.pop();
              if(i==0)
              {
                first = curr_id;
              }
              if(i==size-1)
              {
                last= curr_id;
              }
              if(temp ->left !=NULL)
              {
                q.push({temp ->left , (long)curr_id*2+1});
              }
              if(temp ->right !=NULL)
              {
                q.push({temp ->right , (long)curr_id*2+2});
              }

            }
            ans = max(ans , last-first+1);
        }
        return ans;
        
    }
};