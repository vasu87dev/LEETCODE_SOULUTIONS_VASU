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
vector<vector<int>> st1;
vector<int> st2;
    vector<string> binaryTreePaths(TreeNode* root) {
        binary(root);
vector<string> ans;

for (int j = 0; j < st1.size(); j++)
{
    string s = "";

    for (int i = 0; i < st1[j].size(); i++)
    {
        s += to_string(st1[j][i]);

        if (i != st1[j].size() - 1)
            s += "->";
    }

    ans.push_back(s);
}

return ans;
    }


    void binary(TreeNode* root)
    {
        if(root==NULL)
        {
          
          return ;
        }
st2.push_back(root->val);
if(root->left==NULL &&  root->right==NULL)
{
    st1.push_back(st2);
    //st2.clear();
}
else
{
 binary(root->left);
 binary(root->right);
}
st2.pop_back();
    }
};