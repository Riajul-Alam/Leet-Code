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
const int N=10005;
class Solution {
    unordered_map<TreeNode*,int>dp;
public:
    int rob(TreeNode* root) {
        if(!root)return 0;
        if(dp[root])return dp[root];
        int root1=root->val;
        int fstChild=rob(root->left)+rob(root->right);
        int sndChild1=0,sndChild2=0;
        if(root->left)sndChild1=rob(root->left->left)+rob(root->left->right);
        if(root->right)sndChild2=rob(root->right->left)+rob(root->right->right);
        return dp[root]=max(fstChild,root1+sndChild1+sndChild2);
    }
};