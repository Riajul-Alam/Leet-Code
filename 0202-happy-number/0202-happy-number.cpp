#define toll(a) atoll(a.c_str())
string tostr(int a) {stringstream rr;rr<<a;return rr.str();}
bool PowerOf2(int n){return (n&(n-1))==0;}
int digitSqSum(int n){
    int sum=0;
    while(n>0){
        int x=n%10;
        n/=10;
        sum+=(x*x);
    }
    return sum;
}
class Solution{
public:
    bool isHappy(int n) {
        map<int,int>mp;
        while(1){
            if(mp[n]){
                return false;
            }
            mp[n]++;
            n=digitSqSum(n);
            if(n==1){
                return true;
            }
        }
    }
};


class Solution2 {
public:
    bool isHappy(int n) {
        int c1=0;
        while(1){
            c1++;
            string s;
            s=tostr(n);int sum=0;
            for(int i=0;i<s.size();i++){
                sum+=((s[i]-'0')*(s[i]-'0'));
            }
            n=sum;
            if(c1==100){
                return false;
            }
            if(n==1){
                return true;
            }
        }
        return true;
    }
};