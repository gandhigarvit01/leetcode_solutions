class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        int maxi = 0;
        unordered_map<int,int> mpp;
        while(right<n){
            if(mpp.size()<2){
                if(mpp.find(fruits[right])!=mpp.end()){
                    mpp[fruits[right]]++;
                }
                else{
                    mpp[fruits[right]] = 1;
                }
            }
            else if(mpp.size()==2){
                if(mpp.find(fruits[right])!=mpp.end()){
                    mpp[fruits[right]]++;
                }
                else{
                    mpp[fruits[right]] = 1;
                    while(mpp.size()>2){
                        mpp[fruits[left]]--;
                        if(mpp[fruits[left]]==0){
                            mpp.erase(fruits[left]);
                        }
                        left++;
                    }
                }
            }
            right++;
            maxi = max(maxi,right-left);
        }
        return maxi;
    }
};