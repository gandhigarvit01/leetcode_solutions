class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        int l=1, r=2;
        int ans = 0, curr = 2;
        int diff = nums[1]-nums[0];
        int point=-1, change=0, temp=-1;
        while(r<n){
            int d = nums[r]-nums[r-1];
            if(d==diff){
                curr++;
                ans = max(ans,curr);
                r++;
            }
            else{
                if(change==0){
                    change++;
                    temp = nums[r];
                    nums[r] = nums[r-1] + diff;
                    point = r;
                    curr++;
                    ans = max(ans,curr);
                    r++;
                }
                else{
                    change=0;
                    l = point;
                    point = -1;
                    nums[l] = temp;
                    temp = -1;
                    diff = nums[l]-nums[l-1];
                    curr = 2;
                    r = l+1;
                }
            }
        }
        if(point!=-1){
            nums[point] = temp;
        }
        point = -1, temp = -1, change = 0;
        l = n-2, r = n-3;
        diff = nums[l+1]-nums[l];
        curr = 2;
        while(r>-1){
            int d = nums[r+1]-nums[r];
            if(d==diff){
                curr++;
                ans = max(ans,curr);
                r--;
            }
            else{
                if(change==0){
                    change++;
                    temp = nums[r];
                    point = r;
                    nums[r] = nums[r+1]-diff;
                    curr++;
                    ans = max(ans,curr);
                    r--;
                }
                else{
                    change = 0;
                    l = point;
                    nums[l] = temp;
                    diff = nums[l+1]-nums[l];
                    curr = 2;
                    r = l-1;
                }
            }
        }
        return ans;
    }
};