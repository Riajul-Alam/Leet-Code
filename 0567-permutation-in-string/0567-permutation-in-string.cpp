typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
#define MP make_pair
#define in insert
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int n=s1.size(),m=s2.size();
        vector<char>s;
        map<char,int>mp,mp1;
        for(int i=0;i<n;i++){
            mp[s1[i]]++;
        }
        for(int i=0;i<m;i++){
            int c1=0,c2=0;map<char,int>tm;
            for(int j=i;i+n-1<m && j<m;j++){
                tm[s2[j]]++;c1++;
                if(c1==n)break;
            }
            for(auto q:mp){
                if(q.ss!=tm[q.ff]){
                    c2++;break;
                }
            }
            if(!c2)return true;
        }
        return false;
        
    }
};