class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        string k="";
        int m=-1;
        for(int i=n-1; i>=0; i--){
           if(num[i]%2!=0){
            m=i;
            break;
           }
        }
       return num.substr(0,m+1);
    }
};