class Solution {
public:
    // curr = 1 -> transaction is pending, curr = 0 -> start a new ---- buynow = 1 -> buy now, buynow = 0 -> sell now.
    // using dp.
    long long dp[1000][501][2][2];
    int n;
    long long solve(vector<int>& prices,int i, int k, int curr, int buynow){
        if(dp[i][k][curr][buynow] != -1){
            return dp[i][k][curr][buynow];
        } 
        if(i==n-1){
            if(curr==0){
                return 0;
            }
            else{
                if(buynow==1){
                    long long buy = -1*prices[i];
                    return dp[i][k][curr][buynow] = buy;
                }
                else{
                    long long sell = prices[i];
                    return dp[i][k][curr][buynow] = sell;
                }
            }
        }

        if(k==0){
            return dp[i][k][curr][buynow] = 0;
        }

        long long buy,sell,leave;
        if(curr==0){
            buy = (-1*prices[i]) + solve(prices,i+1,k,1,0);
            sell = prices[i] + solve(prices,i+1,k,1,1);
            leave = solve(prices,i+1,k,0,0);

            return dp[i][k][curr][buynow] = max(leave,max(buy,sell));
        }
        else if(curr==1){
            if(buynow==1){
                buy = (-1*prices[i]) + solve(prices,i+1,k-1,0,0);
                leave = solve(prices,i+1,k,1,1);

                return dp[i][k][curr][buynow] = max(buy,leave);
            }
            else{
                sell = prices[i] + solve(prices,i+1,k-1,0,0);
                leave = solve(prices,i+1,k,1,0);

                return dp[i][k][curr][buynow] = max(sell,leave);
            }
        }
        return 0;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        long long ans = solve(prices,0,k,0,0); // k -> no. of transaction left.
        return ans;
    }
};