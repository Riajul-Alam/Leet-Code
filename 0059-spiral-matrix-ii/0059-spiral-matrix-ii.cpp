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
#define vvl vector<vl>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpl vector<pll>
#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
#define toll(a) atoll(a.c_str())
string tostr(ll a) {stringstream rr;rr<<a;return rr.str();}
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9 + 7;
#define eps 1e-10
#define INF 1e18
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        m=matrix.begin()->size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int up,right,down,left,c1=0,total=n*m;
        up=0;right=m-1;
        down=n-1,left=0;
        int val=1,Count=0;
        while(1)
        {
        	c1=0;
            for(int i=up;i<right;i++){
            	if(Count>=total)break;c1++;
                matrix[up][i]=val;Count++;val++;
                vis[up][i]=1;
            }
            for(int i=up;i<down;i++){
            	if(Count>=total)break;c1++;
                matrix[i][right]=val;Count++;val++;
                vis[i][right]=1;
            }
            for(int i=right;i>left;i--){
            	if(Count>=(total))break;c1++;
                matrix[down][i]=val;Count++;val++;
                vis[down][i]=1;
            }
            for(int i=down;i>up;i--){
            	if(Count>=total)break;c1++;
                matrix[i][left]=val;Count++;val++;
                vis[i][left]=1;
            }
            up++;right--;
            down--;left++;
            if(c1==0){
            	break;
            }
            if(Count>=total)break;
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(vis[i][j]==0){
        			matrix[i][j]=val;val++;
        		}
        	}
        }
        return matrix;
    }
};