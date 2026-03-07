class Solution {
public:
    int minFlips(string s) {
        string t = s + s;
        int n = s.size();
        int ans = INT_MAX;
        int odd_ones = 0, even_zeros = 0, even_ones = 0, odd_zeros = 0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                if(s[i]=='1') even_ones++;
                else even_zeros++;
            }
            else{
                if(s[i]=='1') odd_ones++;
                else odd_zeros++;
            }
        }
        int i=1, j=n;
        while(j<t.size()){
            if(j%2==0){
                if(t[j]=='1') even_ones++;
                else even_zeros++;
            }
            else{
                if(t[j]=='1') odd_ones++;
                else odd_zeros++;
            }
            if((i-1)%2==0){
                if(t[i-1]=='1') even_ones--;
                else even_zeros--;
            }
            else{
                if(t[i-1]=='1') odd_ones--;
                else odd_zeros--;
            }
            ans = min(ans, min(n-(odd_ones+even_zeros),n-(odd_zeros+even_ones)));
            i++, j++;
        }
        return ans;
    }
};