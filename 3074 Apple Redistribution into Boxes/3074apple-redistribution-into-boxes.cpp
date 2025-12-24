class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += apple[i];
        }
        sort(capacity.begin(),capacity.end());
        int sum2 = 0;
        int k = 0;
        for(int i=m-1; i>=0; i--){
            if(sum2 < sum){
                sum2 += capacity[i];
                k++;
            }
            else{
                break;
            }
        }
        return k;
    }
};