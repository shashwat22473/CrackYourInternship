class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans=0;
        stations.push_back({target,0});
        int n=stations.size();
        int prev=0;
        for (int i=0;i<n;i++){
            startFuel-=stations[i][0]-prev;
            while(startFuel<0 && pq.size()>0){
                startFuel+=pq.top();
                ans++;
                pq.pop();
            }
            cout<<startFuel<<endl;
            if (startFuel<0){return -1;}
            pq.push(stations[i][1]);
            prev=stations[i][0];
        }
        return ans;
    }
};
