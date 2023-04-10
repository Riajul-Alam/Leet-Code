
class Solution {
public:    
    bool valid(string temp){
        if(temp.size()>3 || temp.size()==0) return false; 
        if(temp.size()>1 && temp[0]=='0')   return false;
        if(temp.size() && stoi(temp)>255) return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        //we will store our ans in ans vector of strings
        vector<string>ans;
        //the max length of the ip address could be 12 as 255.255.255.255 so 
        //all the string s with size greater than 12 can have ans
        if(n>12){
            return ans;
        }
        //now we have our string of length 12 or less than 12 so now 
            //1. we have to spit the s in parts such that it satisfy the ip address conditions
            //2. if all 4 strings satisfy the condition we will push into ans vector
        
        for(int i=1;i<=3;i++){//for the length before first '.'
            for(int j=1;j<=3;j++){//for the length between first and second '.'
                for(int k=1;k<=3;k++){//for the length between second and third '.'
                    //checking condition if the last segment is of length 3 or less
                    if(i+j+k<n&&i+j+k+3>=n){
                        //dividing the s int substrings 
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(j+i,k);
                        string d=s.substr(i+j+k);
                        //if all the substring satisfy the check function condition 
                        //then we will push into ans vector 
                        if(valid(a)&&valid(b)&&valid(c)&&valid(d)){
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        return ans;

    }
};