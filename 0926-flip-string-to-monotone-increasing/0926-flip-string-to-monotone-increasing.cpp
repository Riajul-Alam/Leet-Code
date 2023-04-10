// 1) set all 0
// 2) set all 1
// 3) back flip 0 to 1 ,before start 1
// 4) before last 0,set all 1 to 0
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans=1e9,one=0,zero=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0')zero++;
            else one++;
        }
        ans=min(zero,one);
        
        int c1=0,last=n;
        // for(int i=n-1;i>=0;i--){
        //     if(s[i]!='0'){
        //         while(i>=0 && s[i]=='1'){
        //             last=i;i--;
        //         }
        //         break;
        //     }
        //     c1++;s[i]=1;
        // }
        int st=0,c2=0;
        // for(int i=0;i<last;i++){
        //     if(s[i]=='0'){st=i;c2++;}
        //     else break;
        // }
        // ans=min(one,zero-c2);
        zero=one=0;
        vector<pair<int,int>>pre(n+5,{0,0}),suf(n+5,{0,0});
        for(int i=0;i<n;i++){
            if(s[i]=='0')zero++;
            else one++;
            pre[i]={one,zero};
        }
        zero=one=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')zero++;
            else one++;
            suf[i]={one,zero};
        }
        for(int i=0;i<n;i++){
            int x,y;
            x=pre[i].first;
            y=suf[i+1].second;
            ans=min(ans,x+y);
        }
        return ans;
    }
};