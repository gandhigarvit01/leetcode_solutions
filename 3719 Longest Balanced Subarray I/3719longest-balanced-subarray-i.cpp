class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int,int> even;
        unordered_map<int,int> odd;
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(nums[j]%2==0){
                    if(even.find(nums[j])!=even.end()) even[nums[j]]++;
                    else even[nums[j]] = 1;
                }
                else{
                    if(odd.find(nums[j])!=odd.end()) odd[nums[j]]++;
                    else odd[nums[j]] = 1;
                }

                if(even.size()==odd.size()){
                    ans = max(ans,j-i+1);
                }
            }
            even.clear();
            odd.clear();
        }
        return ans;
    }
};