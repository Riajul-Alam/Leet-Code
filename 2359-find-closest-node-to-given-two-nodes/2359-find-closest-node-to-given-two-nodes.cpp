#define INF 1e8
const int MN = 100005;
class Solution {
public:
    int depth[MN];
    bool vis[MN];
    vector<int> adj[MN];
    void dfs (int cur) {
      vis[cur]=1;
      for (int i : adj[cur]) if (!vis[i]) {
        if(depth[cur]==INF)depth[cur]=0;
        depth[i] = depth[cur] + 1;
        vis[i]=1;
        dfs(i);
      }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1==node2)return node1;
        int n=edges.size();
        for(int i=0;i<n;i++){
          int x,y;
          if(edges[i]!=-1){
            adj[i].push_back(edges[i]);
          }
        }
        vector<int>depth1,depth2;
        for(int i=0;i<n;i++){
          depth[i]=INF;vis[i]=0;
        }
        dfs(node1);
        for(int i=0;i<n;i++){
          depth1.push_back(depth[i]);
        }
        for(int i=0;i<n;i++){
          depth[i]=INF;vis[i]=0;
        }
        dfs(node2);
        for(int i=0;i<n;i++){
          depth2.push_back(depth[i]);
        }
        int ans=1e9,node=INF;
        for(int i=0;i<n;i++){
          int tmp=max(depth1[i],depth2[i]);
          if(tmp<ans && depth2[i]!=INF && depth1[i]!=INF){
            ans=tmp;node=i;
          }
          else if(tmp==ans && depth2[i]!=INF && depth1[i]!=INF){
            ans=tmp;node=min(i,node);
          }
        }
        if(node==INF){
          if(node==INF){
            int c1=0,c2=0;
            for(int i=0;i<n;i++){
              if(depth1[i]==INF)c1++;
            }
            for(int i=0;i<n;i++){
              if(depth2[i]==INF)c2++;
            }
            if(c1==n && depth2[node1]!=INF)node=node1;
            else if(c2==n && depth1[node2]!=INF)node=node2;
            else{
              node=-1;
            }
          }
        }
        return node;
    }
};