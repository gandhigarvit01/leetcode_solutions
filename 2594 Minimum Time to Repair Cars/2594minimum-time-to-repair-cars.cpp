class Solution {
public:
    bool rc(vector<int>& ranks, long long n, int cars, long long m){
       long long count = 0;
       for(long long rank : ranks){
        count += sqrt(m/rank);
       }
       return count>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long  n = ranks.size();
        long long  mini = INT_MAX;
        for(int i=0; i<n; i++){
            if(ranks[i]<mini){
                mini = ranks[i];
            }
        }
        long long l=1;
        long long r=(long long)mini*cars*cars;
        long long mid=0;
        long long ans=0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(rc(ranks,n,cars,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};