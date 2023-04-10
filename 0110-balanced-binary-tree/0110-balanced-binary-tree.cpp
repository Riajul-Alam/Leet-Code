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
    int dfs(TreeNode* root,bool &flag){
        if(root==NULL)return 0;
        int ans=1,l=0,r=0;
        r=dfs(root->right,flag);
        l=dfs(root->left,flag);
        if(abs(l-r)>1)flag=1;
        ans=max(l,r)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        bool flag=0;
        dfs(root,flag);
        if(flag)return 0;
        else return 1;
    }
};