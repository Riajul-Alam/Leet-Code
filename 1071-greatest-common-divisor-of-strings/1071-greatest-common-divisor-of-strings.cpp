class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        string t="",ans="";
        int gcd=__gcd(s1.size(),s2.size());
        ans=s1.substr(0,gcd);
        if(s1+s2!=s2+s1)return "";
        return ans;
    }
};
class Solution2 {
public:
    string gcdOfStrings(string s1, string s2) {
        string t="",ans="";
        if(s1.size()>s2.size()){
            swap(s1,s2);
        }
        for(int i=0;i<s1.size();i++){
            t+=s1[i];int c1=0,flag=0;
            for(int j=0;j<s1.size();j++){
                string tmp;
                while(t.size()!=tmp.size() && j<s1.size()){
                    tmp+=s1[j];j++;
                }j--;
                if(t.size()!=tmp.size() || tmp!=t){
                    flag=1;break;
                }
            }
            if(flag)continue;
            for(int j=0;j<s2.size();j++){
                string tmp;
                while(t.size()!=tmp.size() && j<s2.size()){
                    tmp+=s2[j];j++;
                }
                j--;
                if(t.size()!=tmp.size() || tmp!=t){
                    flag=1;break;
                }
            }
            if(flag)continue;
            ans=t;
        }
        return ans;
    }
};