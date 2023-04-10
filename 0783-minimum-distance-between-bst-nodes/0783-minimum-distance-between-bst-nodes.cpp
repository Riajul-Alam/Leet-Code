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
    
    vector<int>s;
    void f(TreeNode* root){
        if(root==NULL)return;
        s.push_back(root->val);
        f(root->right);
        f(root->left);return;
    }
    int minDiffInBST(TreeNode* root) {
        f(root);
        sort(s.begin(),s.end());
        int mn=1e9;
        for(int i=1;i<s.size();i++){
            mn=min(mn,s[i]-s[i-1]);
        }
        return mn;
    }
};