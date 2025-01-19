class Solution {
public:
    void reverse(vector<int> & arr ,int x, int y){
        int start=x;
        int end=y;
        while(start<end){
            swap(arr[start],arr[end]);
            start++;
            end--;

        }
    }
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        k=k%n;
        reverse(nums, 0, n-1-k);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
};