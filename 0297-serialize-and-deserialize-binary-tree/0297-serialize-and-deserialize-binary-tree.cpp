/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root == NULL)
        {
            return "";
        }
        string str = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL)
            {
                str.append("#,");  // Append "#," for NULL node
            }
            else
            {
                str.append(to_string(node->val) + ',');  // Append value + ','
            }
            if(node != NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            // Process left child
            getline(s,str,',');
            if(str == "#")
            {
                temp->left = NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                temp->left = leftNode;
                q.push(leftNode);  // Correct variable to push
            }
            
            // Process right child
            getline(s,str,',');
            if(str == "#")
            {
                temp->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                temp->right = rightNode;
                q.push(rightNode);  // Correct variable to push
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));