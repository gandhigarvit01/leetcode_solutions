class Solution {
public:
    vector<int> segmentree;
    void build(int i, int l, int r, vector<int>& heights){
        if(l==r){
            segmentree[i] = l;
            return;
        }
        int mid = (l+r)/2;
        build(2*i+1,l,mid,heights);
        build(2*i+2,mid+1,r,heights);
        int left = segmentree[2*i+1];
        int right = segmentree[2*i+2];
        if(heights[left]>=heights[right]){
            segmentree[i] = left;
        }
        else{
            segmentree[i] = right;
        }
    }
    int rmiq(int i, int l, int r, int start, int end, int threshold, vector<int>& heights){
        if(l==r && l>=start && l<=end){
            return segmentree[i];
        }
        if(r<start || l>end) return -1;
        if(heights[segmentree[i]]<=threshold) return -1;
        int mid = (l+r)/2;
        int left = rmiq(2*i+1,l,mid,start,end,threshold,heights);
        if(left!=-1 && heights[left]>threshold){
            return left;
        }
        int right = rmiq(2*i+2,mid+1,r,start,end,threshold,heights);
        if(right!=-1 && heights[right]>threshold) return right;
        return -1;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segmentree.resize(4*n);
        build(0,0,n-1,heights);
        int m = queries.size();
        vector<int> result;
        for(int i=0; i<m; i++){
            int a = min(queries[i][0],queries[i][1]), b = max(queries[i][0],queries[i][1]);
            if(a==b || heights[b]>heights[a]){
                result.push_back(b);
            }
            else{
                int threshold_height = heights[a];
                int start = b+1;
                int end = n-1;
                int ans = rmiq(0,0,n-1,start,end,threshold_height,heights);
                result.push_back(ans);
            }    
        }
        return result;
    }
};