class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;
        priority_queue<int> pq;
        int i = n-1;
        while(i>=0){
            if(s[i]=='1'){
                pq.push(nums[i]);
            }
            else{
                pq.push(nums[i]);
                while(pq.size()!=1){
                    int val = pq.top();
                    pq.pop();
                    ans += val;
                }
                pq.pop();
            }
            i--;
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};