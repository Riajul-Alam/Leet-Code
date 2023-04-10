class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,char>mp;
        char ch;ch='a';
        for(int i=0;i<order.size();i++){
            mp[order[i]]=ch;ch++;
        }
        vector<string>s1;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                words[i][j]=mp[words[i][j]];
            }
        }
        for(int i=1;i<words.size();i++){
            int ind=0,c1=0;
            for(int j=0;j<min(words[i-1].size(),words[i].size());j++){
                if(words[i-1][j]==words[i][j]){
                    continue;
                }
                else if(words[i-1][j]<words[i][j]){
                    c1++;
                    break;
                }else if(words[i-1][j]>words[i][j]){
                    return false;
                }
            }
            if(c1==0){
                if(words[i-1].size()>words[i].size()){
                    return false;
                }   
            }
        }
        return true;
    }
};