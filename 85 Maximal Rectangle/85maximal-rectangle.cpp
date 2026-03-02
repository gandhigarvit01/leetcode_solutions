class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            int curr = 0;
            int j=i;
            unordered_set<int> st1;
            unordered_set<int> st2;
            for(int k=0; k<n; k++){
                if(matrix[j][k]=='0') curr = 0;
                else{
                    curr++;
                    ans = max(curr,ans);
                    st1.insert(k);
                }
            }
            for(j=i+1; j<m; j++){
                st2.clear();
                curr = 0;
                for(int k=0; k<n; k++){
                    if(matrix[j][k]=='1' && st1.count(k)){
                        curr++;
                        ans = max(ans,curr*(j-i+1));
                        st2.insert(k);
                    }
                    else curr = 0;
                }
                st1.swap(st2);
                st2.clear();
            }
        }
        return ans;
    }
};