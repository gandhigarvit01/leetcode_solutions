class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int mondaymoney = 0;
        int k = 0;
        for(int i=1; i<=n; i++){
            if(i%7==1){
                mondaymoney++;
                k = mondaymoney;
            }
            else{
                k++;
            }
            ans += k;
        }
        return ans;
    }
};