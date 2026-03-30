class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> vec;
        for(int i=0; i<n; i++){
            if(dominoes[i]!='.') vec.push_back(i);
        }
        int m = vec.size();
        for(int k=0; k<m; k++){
            if(dominoes[vec[k]]=='L'){
                int idx = 0;
                if(k-1>=0 && dominoes[vec[k-1]]=='L')
                {
                    idx = vec[k-1];
                }
                if(k-1>=0 && dominoes[vec[k-1]]=='R')
                { 
                    idx = vec[k] - (vec[k]-vec[k-1]-1)/2;
                }
                for(int i=vec[k]; i>=idx; i--){
                    dominoes[i] = 'L';
                }
            }
            else{
                int idx = n-1;
                if(k+1<m && dominoes[vec[k+1]]=='R')
                {
                    idx = vec[k+1];
                }
                if(k+1<m && dominoes[vec[k+1]]=='L')
                {
                    idx = vec[k] + (vec[k+1]-vec[k]-1)/2;
                }
                for(int i=vec[k]; i<=idx; i++){
                    dominoes[i] = 'R';
                }
            }
        }
        return dominoes;
    }
};