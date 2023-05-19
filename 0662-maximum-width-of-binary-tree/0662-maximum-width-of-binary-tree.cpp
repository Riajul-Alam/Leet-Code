//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
#define in insert
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define print1(x) cout<<x<<endl;
#define print2(x,y) cout<<x<<" "<<y<<endl;
#define print3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
#define mem(a,b) memset(a,b,sizeof(a))
#define toll(a) atoll(a.c_str())
string tostr(int a) {stringstream rr;rr<<a;return rr.str();}
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9 + 7;
#define eps 1e-10
#define INF 2e9
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int maxWidth = 0;
        queue<TreeNode*> node_q;
        queue<unsigned long long> index_q;
        node_q.push(root);
        index_q.push(1);
        while (!node_q.empty()) {
            int size = node_q.size();
            unsigned long long leftIndex = index_q.front(), rightIndex = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = node_q.front();
                unsigned long long index = index_q.front();
                node_q.pop();
                index_q.pop();
                rightIndex = index;
                if (curr->left) {
                    node_q.push(curr->left);
                    index_q.push(index * 2);
                }
                if (curr->right) {
                    node_q.push(curr->right);
                    index_q.push(index * 2 + 1);
                }
            }
            maxWidth = max(maxWidth, (int)(rightIndex - leftIndex + 1));
        }
        return maxWidth;
    }
};