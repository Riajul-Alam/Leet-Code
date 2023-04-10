class Solution {
public:
    unordered_map<string,int>mp;
    int f(int i,string cur,string &s,int Count){
        if(i==s.size()-1){
            cur+=s[i];
            if(mp[cur])Count++;
            if(mp[cur] && Count>1){
                return 1;
            }return 0;
        }
        cur+=s[i];
        int x=0,y=0;
        if(i+1<s.size()){
            x=f(i+1,cur,s,Count);
        }
        if(i+1<s.size()){
            if(mp[cur]){Count++;y=f(i+1,"",s,Count);}
        }
        return x|y;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<string>result;
        for(int i=0;i<words.size();i++){
            if(f(0,"",words[i],0)){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};