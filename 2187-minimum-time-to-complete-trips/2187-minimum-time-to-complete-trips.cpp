#define ll long long
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll start=0;
        ll end =1e14;
        while(start+1<end){
            ll trip = 0;
            ll mid = start + (end - start)/2;
            for(int i=0;i<time.size();i++)
                trip += mid / time[i];
            if(trip < totalTrips){
                start = mid;
            }
            else 
                end = mid;
        }
        return start+1;
    }
};
