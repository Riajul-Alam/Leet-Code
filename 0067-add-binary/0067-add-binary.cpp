class Solution {
public:
    string addBinary(string a, string b) {
        string answer;answer="";
        int i=a.size()-1,j=b.size()-1,carry=0;
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1' && carry){
                answer='1'+answer;carry=1;
            }
            else if(a[i]=='1' && b[j]=='1'){
                answer='0'+answer;carry=1;
            }else if(a[i]=='1' && carry){
                answer='0'+answer;
            }else if(b[j]=='1' && carry){
                answer='0'+answer;
            }
            else if(carry){
                answer='1'+answer;carry=0;
            }
            else if(a[i]=='1'){
                answer='1'+answer;
            }
            else if(b[j]=='1'){
                answer='1'+answer;
            }
            else{
                answer='0'+answer;
            }
            i--,j--;
        }
        while(i>=0){
            if(carry && a[i]=='1'){
                answer='0'+answer;
            }else if(carry || a[i]=='1'){
                answer='1'+answer;carry=0;
            }else{
                answer=a[i]+answer;
            }i--;
        }
        while(j>=0){
            if(carry && b[j]=='1'){
                answer='0'+answer;
            }else if(carry || b[j]=='1'){
                answer='1'+answer;carry=0;
            }else{
                answer=b[j]+answer;
            }j--;
        }
        if(carry){
            answer='1'+answer;
        }
        return answer;
    }
};