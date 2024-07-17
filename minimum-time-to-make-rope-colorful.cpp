class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=neededTime[0];;
        int n=colors.size();
        int count_=neededTime[0];
        for (int i=1;i<n;i++){
            if (colors[i]==colors[i-1] ){count_=max(count_,neededTime[i]);ans+=neededTime[i];}
            else {
                ans-=count_;
                count_=neededTime[i];
                ans+=neededTime[i];
                
            }
        }
        ans-=count_;
        return ans;
    }
};
