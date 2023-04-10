class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int low =-1;
       int high = arr.size();
       int mid;
       while (low+1<high) {
            mid=(low + high)/2;
            if (arr[mid]-(mid+1)<k)low=mid;
            else{
                high=mid;
            }  
        }
        return low+k+1;
    }
};
