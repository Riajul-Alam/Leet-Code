#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n,m;n=sz(mat);m=sz(mat[0]);
        vvi vis(n,vi(m,0));
        vvi dist(n,vi(m,0));
        queue<pair<pii,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty())
        {
            auto u=q.front();q.pop();
            int x=u.ff.ff,y=u.ff.ss,level=u.ss;
            dist[x][y]=level;
            for(int i=0;i<4;i++){
                int r,c;
                r=x+X[i];
                c=y+Y[i];
                if(valid(r,c,n,m,vis)){
                    vis[r][c]=1;
                    q.push({{r,c},level+1});
                }
            }
        }
        return dist;
    }
    bool valid(int x,int y,int n,int m,vvi &vis){
        return (x>=0 && x<n && y>=0 && y<m && vis[x][y]==0);
    }
};