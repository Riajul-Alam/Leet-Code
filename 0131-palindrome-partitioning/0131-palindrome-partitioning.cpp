bool palindrome(string s)
{
    int n=s.size();
    int i=0,j=n-1,c1=0;
    while(i<=j){
      if(s[i]!=s[j]){
        c1++;break;
      }else{
        i++,j--;
      }
    }
    return c1==0;
}
class Solution {
public:
    vector<vector<string>>allPalin;
    void f(int i,string s,string cur,vector<string>Partition){
        if(i==s.size()){
            int n,c1=0;
            n=Partition.size();
            for(int j=0;j<n;j++){
                if(!palindrome(Partition[j]))return;
                c1+=Partition[j].size();
            }
            if(s.size()!=c1)return;
            allPalin.push_back(Partition);return;
        }
        cur+=s[i];        
        f(i+1,s,cur,Partition);
        Partition.push_back(cur);
        f(i+1,s,"",Partition);
    }
    vector<vector<string>> partition(string s) {
        string tm;
        vector<string>Partition;
        f(0,s,"",Partition);
        return allPalin;
    }
};