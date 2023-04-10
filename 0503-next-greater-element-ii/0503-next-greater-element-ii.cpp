class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int>store;int n=nums.size();
    vector<int>NextElement(n,-1);
    for(int i=2*n-1;i>=0;i--){
    	while(!store.empty() && store.top()<=nums[i%n]){
    		store.pop();
    	}
    	if(!store.empty()){
    		NextElement[i%n]=store.top();
    	}
    	store.push(nums[i%n]);
    }
        return NextElement;
    }
};