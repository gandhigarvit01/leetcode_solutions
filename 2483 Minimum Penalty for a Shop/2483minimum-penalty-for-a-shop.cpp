class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = 0;
        int n = customers.size();
        for(int i=0; i<n; i++){
            if(customers[i]=='Y'){
                ans++;
            }
        }
        int k = ans;
        int idx = -1;
        for(int i=0; i<n; i++){
            if(customers[i]=='Y'){
                ans--;
            }
            else if(customers[i]=='N'){
                ans++;
            }
            if(ans<k){
                k = ans;
                idx = i;
            }
        }
        return idx>=0?idx+1:0;
    }
};