typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld; 
#define pb push_back
#define ff first
#define ss second
#define MP make_pair
#define pf push_front
#define in insert
#define ppb pop_back
#define ppf pop_front
#define nl '\n'
#define sp ' '

#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpl vector<pll>
#define vpls vector<pair<ll,string>
#define vpsl vector<pair<string,ll>>

#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define f1(i,l,r) for(int i=l;i<r;i++)
#define rf1(i,r,l) for(int i=r-1;i>=l;i--)
#define f2(i,l,r) for(int i=l;i<=r;i++)
#define rf2(i,r,l) for(int i=r;i>=l;i--)
#define print1(x) cout<<x<<endl;
#define print2(x,y) cout<<x<<" "<<y<<endl;
#define print3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) count(v.begin(),v.end(),a)
#define mem(a,b) memset(a,b,sizeof(a))
#define Find(a,x) find(all(a),x)
#define LB(a,X) lower_bound(all(a),X)-a.begin()
#define UB(a,X) upper_bound(all(a),X)-a.begin()
#define toll(a) atoll(a.c_str())
string tostr(ll a) {stringstream rr;rr<<a;return rr.str();}
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const ll mod = 1e9 + 7;
#define eps 1e-10
#define INF 1e18
#define N 505
class Solution {
public:
    string s,t;
    int dp[N][N];
    int lcs(ll i,ll j){
        if(i==sz(s)|| j==sz(t)){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int x=0,y=0;
        if(s[i]==t[j]){
            x=1+lcs(i+1,j+1);
            dp[i][j]=x;
        }
        else{
            if(s[i]!=t[j]){
                x=lcs(i+1,j);
                y=lcs(i,j+1);
            }
            if(x>y){
                dp[i][j]=x;
            }else{
                dp[i][j]=y;
            }		
        }
        return dp[i][j];
    }
    int solve(string s1,string t1)
    {
        int n,m,k,x,y,z,sum=0,c1=0,c2=0,ans=0;
        mem(dp,-1);
        s=s1,t=t1;
        n=s.size(),m=t.size();
        ans=lcs(0,0);
        return ans;
    }
    int minDistance(string word1, string word2) {
        int x=sz(word1)+sz(word2)-2*solve(word1,word2);
        return x;
    }
};