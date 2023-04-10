typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld; 
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()

class Solution {
public:
    // Grid direction array [4]
    int X[4]={0,0,-1,1};
    int Y[4]={1,-1,0,0};
    bool valid(int x,int y,int nx,int my,vector<vector<int>>&visited){
        return (x>=0 && x<nx && y>=0 && y<my && !visited[x][y]);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n,m;n=sz(grid),m=sz(grid[0]);
        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=grid[i][j];
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        if(sz(q)==0 || sz(q)==(n*m)){
            return -1;
        }
        int dis=0;
        while(!q.empty()){
            dis++;
            int cur=q.size();// doing this because of finding distance/level 
            while(cur--){
                auto u=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int x=X[i]+u.ff;
                    int y=Y[i]+u.ss;
                    if(valid(x,y,n,m,vis)){
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
        return dis-1;
    }
};