/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second

class Solution {
public:
    int guessNumber(int n){
        long long int l=-1,r=n;
        while(l+1<r){
            int mid=((r-l)>>1)+l;
            int x=guess((int)mid);
            if(x==-1 || x==0){
                r=mid;
            }else{
                l=mid;
            }
        }
        return int(r);
    }
};