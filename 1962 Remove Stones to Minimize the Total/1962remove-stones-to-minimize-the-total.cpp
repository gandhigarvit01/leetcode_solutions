class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int sum = 0;
        int removed = 0;
        priority_queue<int> pq;   // max heap
        for(int i=0; i<n; i++){
            sum += piles[i];
            pq.push(piles[i]);
        }
        while(k>0){
            int stones = pq.top();
            int remove = stones/2;
            removed += remove;
            pq.pop();
            pq.push(stones-remove);
            k--;
        }
        return sum-removed;;
    }
};