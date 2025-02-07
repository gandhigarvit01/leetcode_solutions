class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c=0,k=0;
        int n=bills.size();
        for(int i=0; i<n; i++){
            if(bills[i]==5){
                c++;
            }
            else if(bills[i]==10){
                c--;
                k++;
            }
            else{
                if(k>0){
                    k--;
                    c--;
                }
                else{
                    c -= 3;
                }
            }
            if(c<0) return false;
        }
        return true;
    }
};