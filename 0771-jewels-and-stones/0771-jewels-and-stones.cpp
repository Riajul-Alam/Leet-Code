//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    int numJewelsInStones(string s, string t) {
        map<char,int>mp;
        int ans=0;
        for(int i=0;i<t.size();i++){
            int c1=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]==t[i]){
                    c1++;
                }
            }
            ans+=c1;
        }
        return ans;
    }
};