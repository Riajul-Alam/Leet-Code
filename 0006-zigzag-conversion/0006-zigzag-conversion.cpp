class Solution {
public:
    string convert(string s, int n) {
        if(n==1)return s;
        vector<string>rows(n);
        int down=1;
        for(int i=0,j=0;i<s.size();i++){
            rows[j].push_back(s[i]);
            if(down){
                if(j==n-1){
                    j--;down=0;
                }else{
                    j++;
                }
            }
            else{
                if(j==0){
                    j++;down=1;
                }else{
                    j--;
                }
            }
        }
        string res;
        for(int i=0;i<rows.size();i++){
            res+=rows[i];
        }
        return res;
    }
};