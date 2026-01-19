class Solution {
public:
    int sumofdiv(int m){
        int sum = 0;
        int div = 0;
        double root = sqrt(m);
        if(floor(root)==root){
            return 0;
        }
        for(int i=1; i<sqrt(m); i++){
            if(m%i==0){
                div++;
                sum += i;
                sum += m/i;
            }
        }
        div = 2*div;
        return div==4?sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            ans += sumofdiv(nums[i]);
        }
        return ans;
    }
};