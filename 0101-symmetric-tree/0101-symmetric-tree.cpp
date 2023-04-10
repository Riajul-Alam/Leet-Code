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
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
    bool check(TreeNode* n1,TreeNode* n2){
        if(!n1&&!n2)return 1;
        if(!n1 || !n2)return 0;
        return (n1->val==n2->val && check(n1->right,n2->left) && check(n1->left , n2->right));
    }
};