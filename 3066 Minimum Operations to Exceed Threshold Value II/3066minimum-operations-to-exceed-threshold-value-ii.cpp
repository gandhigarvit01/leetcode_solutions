class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int operations = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        while(!pq.empty()){
            long long a = pq.top();
            pq.pop();
            if(a>=k){
                break;
            }
            long long b = pq.top();
            pq.pop();
            operations++;
            long long c = min(a,b)*2 + max(a,b);
            pq.push(c);
        }
        return operations;
    }
};