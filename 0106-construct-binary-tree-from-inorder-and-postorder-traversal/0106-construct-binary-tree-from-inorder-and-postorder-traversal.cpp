//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second

#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define sz(cont) (int)(cont).size()

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
    TreeNode* dfs(vi&in,int x,int y,vi&po,int a,int b){
        if(x>y || a>b)return NULL;
        TreeNode *node = new TreeNode(po[b]);
        int ind=x;
        while(po[b]!=in[ind])ind++;
        node->left=dfs(in,x,ind-1,po,a,a+ind-x-1);
        node->right=dfs(in,ind+1,y,po,a+ind-x,b-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int nodes=sz(in)-1;
        return dfs(in,0,nodes,post,0,nodes);
    }
};











