class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int ,vector<int>,greater<int>> pq;
        long long int summ1=0;long long int summ2=0;
        int n=heights.size();
        for (int i=0;i<n-1;i++){
            if (heights[i]<heights[i+1]){
                summ1+=((long long )heights[i+1]-(long long )heights[i]);
                summ2+=((long long )heights[i+1]-(long long )heights[i]);
                pq.push((heights[i+1]-heights[i]));
                if (pq.size()>ladders){summ1-=(long long )pq.top();pq.pop();}
            }
            if (pq.size()==ladders && summ2-summ1>(long long )bricks ){return i;}
        }
        return n-1;
    }
};
