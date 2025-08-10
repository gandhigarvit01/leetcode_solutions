class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> arr(10,0);
        while(n!=0){
            int temp = n%10;
            arr[temp]++;
            n = n/10;
        }
        for(int i=0; i<31; i++){
            int m = 1<<i;
            vector<int> arr1 = arr;
            while(m!=0){
                int temp = m%10;
                arr1[temp]--;
                m = m/10;
            }
            int zeros = 0;
            for(int i=0; i<=9; i++){
                if(arr1[i]==0){
                    zeros++;
                }
            }
            if(zeros==10) return true;
        }
        return false;
    }
};