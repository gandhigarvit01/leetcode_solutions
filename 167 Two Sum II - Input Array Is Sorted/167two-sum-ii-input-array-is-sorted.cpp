class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0,r=n-1,k=target,sum=0;
        vector<int> v(2,0);
        while(l<r){
            sum=numbers[l]+numbers[r];
            if(sum>target){
                r--;
            }
            else if(sum<target){
                l++;
            }
            else{
                v[0]=l+1;
                v[1]=r+1;
                return v;
            }
        }
        return v;
    }
};