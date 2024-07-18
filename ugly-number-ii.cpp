class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        pq.push(1);
        long long int ans=0;
        unordered_map<long long int,int> mapp;
        mapp[1]=1;
        for (int i=0;i<n;i++){
            ans=pq.top();
            pq.pop();
            if (mapp[ans*2]==0){pq.push(ans*2);mapp[ans*2]=1;}
            if (mapp[ans*3]==0){pq.push(ans*3);mapp[ans*3]=1;}
            if (mapp[ans*5]==0){pq.push(ans*5);mapp[ans*5]=1;}
        }
        return ans;
    }
};
