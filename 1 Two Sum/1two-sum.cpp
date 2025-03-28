class Solution {

public:

    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();

        int a;

        int more;

        map<int,int> mpp;

        for(int i=0; i<n; i++){

            a=nums[i];

            more=target-a;

            if(mpp.find(more)!=mpp.end()){

                return {mpp[more],i};

            }

            else{

                mpp[a]=i;

            }

        }

        return {-1,-1};

    

    }

         

};


        

