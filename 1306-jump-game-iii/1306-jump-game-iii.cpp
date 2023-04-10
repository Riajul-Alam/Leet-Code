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

class Solution {
public:
    int f(int i,vector<int>&a,vector<int>&vis){
        if(i>=sz(a) || i<0)return 0;
        if(a[i]==0)return 1;
        if(vis[i])return 0;
        int x=0,y=0;
        vis[i]=1;
        x=f(i+a[i],a,vis);
        y=f(i-a[i],a,vis);
        return x|y;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=sz(arr);
        vector<int>vis(n+5,0);
        return f(start,arr,vis);
    }
};