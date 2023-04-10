#define ll long long int 
ll Set(ll N,ll pos){return N=N|(1LL<<pos);}
ll unSet(ll N,ll pos){return N&(~(1LL<<pos));}
ll toggle(ll N, ll pos) {return  N = N & ~(1LL<<pos);}
bool check(ll N, ll pos) {return  (bool)(N & (1LL<<pos));}
#define  setbits(x)     __builtin_popcountll(x) 
#define  zerobits(x)    __builtin_ctzll(x)
#define  popCount(x)    63LL-__builtin_clzll(ll(x))
#define  popCount1(x)   __lg(ll(x))

class Solution {
public:
    vector<int> countBits(int n) {
       vector<int>ans;ans.push_back(0);
        for(int i=1;i<=n;i++){
            int c1=0;
            for(int j=0;j<32;j++){
                if(check(i,j)){
                  c1++;  
                }
            }ans.push_back(c1);
        }
        return ans;
    }
};