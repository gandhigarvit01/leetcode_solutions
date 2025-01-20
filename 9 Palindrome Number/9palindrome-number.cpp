class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        long int digit,rev =0;

        if(x<0){
            return false;
        }
        else{
             while(x!=0){
                digit = x%10;
                rev = (rev*10) + digit;
                x = x/10;

             }
             if(num==rev){
                return true;
             }
        }
        return false;
    }
};