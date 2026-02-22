class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int active=0, p1=0, p2=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if((((nums[i])%2)!=0)){
                if(active==0) active = 1;
                else active = 0;
            }
            if(((i)%6)==5){
                if(active==0) active = 1;
                else active = 0;
            }
            if(active==0) p1 += nums[i];
            else p2 += nums[i];
        }
        return p1-p2;
    }
};