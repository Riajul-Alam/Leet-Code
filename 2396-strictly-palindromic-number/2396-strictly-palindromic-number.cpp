//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        int n1=n;
        string s,t;
        for(int base=2;base<=n-2;base++)
        {
            int n2=n;
            while(n2>0){
                int rem=n2%base;
                n2/=base;
                string t1=to_string(rem);
                reverse(t1.begin(),t1.end());
                s+=t1;
            }
            t=s;
            reverse(s.begin(),s.end());
            if(t!=s)return false;
        }
        return true;
    }
};