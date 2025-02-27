class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[arr[i]] = 1;
        }
        int x1=0,x2=0,x3=0,c=0,k=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                x1 = arr[i];
                x2 = arr[j];
                x3 = x1+x2;
                c=2;
                while(mpp.find(x3)!=mpp.end()){
                    c++;
                    x1 = x2;
                    x2 = x3;
                    x3 = x1+x2;
                }
                k = max(c,k);
            }
        }
        return k==2?0:k;
    }
};