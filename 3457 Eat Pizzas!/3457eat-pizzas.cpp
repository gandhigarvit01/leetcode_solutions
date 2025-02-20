class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n=pizzas.size();
        int m=n/4;
        int l=0,k=0,j=0,r=n-1;
        long long sum=0;
        sort(pizzas.begin(),pizzas.end());
        if(m%2==0){
            l=m/2;
            k=m/2;
        }
        else{
            l=m/2;
            k=m/2+1;
        }
        while(k>0){
            sum += pizzas[r];
            r -= 1;
            k--;
        }
        r--;
        while(l>0){
            sum += pizzas[r];
            r -= 2;
            l--;
        }
        return sum;
    }
};