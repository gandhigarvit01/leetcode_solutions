class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long score = 0;
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        while(k--){
            int x = pq.top();
            score += x;
            pq.pop();
            int y = ceil((double)x/3);
            pq.push(y);
        }
        return score;
    }
};