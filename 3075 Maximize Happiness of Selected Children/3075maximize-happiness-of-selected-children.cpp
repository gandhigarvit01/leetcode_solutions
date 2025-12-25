class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(),happiness.end());
        int subtractor = 0;
        for(int i=n-1; i>=0; i--){
            if(happiness[i]-subtractor <= 0){
                happiness[i] = 0;
            }
            else{
            happiness[i] -= subtractor;
            }
            subtractor++;
        }
        long long sum = 0;
        for(int i=1; i<=k; i++){
            sum += happiness[n-i];
        }
        return sum;
    }
};