class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> haha(n+1);
        for (int i=0;i<n;i++){
            haha[i+1]=gas[i]-cost[i];
        }
        int ans=0;
        int temp=0;
        for (int i=0;i<n;i++){
            temp+=haha[i+1];
            haha[i+1]+=haha[i];
            if (temp<0){
                ans=i+1;
                temp=0;
            }
        }
        if (haha[n]<0){return -1;}
        return ans;
    }
};
