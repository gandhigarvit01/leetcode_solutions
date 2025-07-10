class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;
        int last = 1;
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                candies += last;
                last++;
            }
            else if(ratings[i]==ratings[i-1]){
                last = 1;
            }
            else{
                int l = i-1;
                int lcandy = last;
                last = 1;
                int j = i;
                while(j+1<n && ratings[j+1]<ratings[j]){
                    j++;
                }
                int k = j;
                while(k!=l+1){
                    k--;
                    candies += last;
                    last++;
                }
                if(lcandy<=last){
                    candies += last+1-lcandy;
                }
                i = j;
                last = 1;
            }
        }
        return candies;
    }
};