class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();string tm;
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].size();i++){
            int c1=0,c2=0;
            for(int j=0;j<n;j++){
                if(i>strs[0].size()-1){
                    c2++;
                    break;
                }
                if(strs[j][i]==strs[0][i])c1++;
            }
            if(c2)break;
            cout<<c1<<endl;
            if(c1==n)tm+=strs[0][i];
            else break;
        }
        return tm;
    }
};