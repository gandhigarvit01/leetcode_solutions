class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> vec(10,0);
        while(n>0){
            int rem = n%10;
            vec[rem]++;
            n = n/10;
        }
        int ans = 0;
        for(int i=1; i<=9; i++){
            ans += i*vec[i];
        }
        return ans;
    }
};