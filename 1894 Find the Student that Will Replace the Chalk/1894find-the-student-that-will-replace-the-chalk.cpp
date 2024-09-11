class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n= chalk.size();
        long long int sum=0;
        for(int i=0; i<n; i++){
           sum = sum + chalk[i];    
        }

        if(k>sum){
            k= k%sum;
        }
        
        for(int i=0; i<=n; i++){
            if(k>=chalk[i] && i!=n){
                k=k-chalk[i];
            }
            else{
                if(i==n){
                    return 0;
                }
                else
                return i;
            }
        }

return chalk[0];

    }
};