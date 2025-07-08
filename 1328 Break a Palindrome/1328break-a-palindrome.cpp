class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1){
            return "";
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(palindrome[i]!='a'){
                if(n%2!=0 && i==n/2){
                }
                else{
                palindrome[i] = 'a';
                break;
                }
            }
            else{
                count++;
            }
        }
        if(count==n || count==n-1){
            palindrome[n-1] = 'b';
        }
        return palindrome;
    }
};