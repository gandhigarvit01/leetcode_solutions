class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int x = minutes-1;
        int l=0, r=0, curr=0, sum=0;
        while(r<=x){
            if(grumpy[r]==1){
                curr += customers[r];
            }
            sum = max(sum,curr);
            r++;
        }
        l++;
        while(r<n){
            if(grumpy[r]==1){
                curr += customers[r];
            }
            if(grumpy[l-1]==1){
                curr -= customers[l-1];
            }
            sum = max(sum,curr);
            l++,r++;
        }
        for(int i=0; i<n; i++){
            if(grumpy[i]==0){
                sum += customers[i];
            }
        }
        return sum;
    }
};