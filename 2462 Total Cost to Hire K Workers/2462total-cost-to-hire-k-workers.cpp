class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        int n = costs.size();
        int l=0, r=n-1;
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        while(candidates>0 && l<=r){
            if(l==r){
                pq1.push(costs[l]);
            }
            else{
                pq1.push(costs[l]);
                pq2.push(costs[r]);
            }
            l++;
            r--;
            candidates--;
        }
        while(k>0){
            if(pq1.empty()){
                ans += pq2.top();
                pq2.pop();
            }
            else if(pq2.empty()){
                ans += pq1.top();
                pq1.pop();
            }
            else{
                int a = pq1.top();
                int b = pq2.top();
                if(a<=b){
                    ans += a;
                    pq1.pop();
                    if(l<=r){
                        pq1.push(costs[l]);
                        l++;
                    }
                }
                else{
                    ans += b;
                    pq2.pop();
                    if(l<=r){
                        pq2.push(costs[r]);
                        r--;
                    }
                }
            }
            k--;
        }
        return ans;
    }
};