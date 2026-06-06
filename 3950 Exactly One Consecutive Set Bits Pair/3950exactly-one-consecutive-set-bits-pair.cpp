class Solution {
public:
    bool consecutiveSetBits(int n) {
        vector<int> vec;
        for(int i=0; i<20; i++){
            if(((1<<i) & (n))!=0){
                vec.push_back(i);
            }
        }
        int m = vec.size();
        int ans = 0;
        for(int i=1; i<m; i++){
            if(vec[i]-vec[i-1]==1){
                ans++;
            }
        }
        return ans==1;
    }
};