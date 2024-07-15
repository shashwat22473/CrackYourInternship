class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ans=0;
        int haha=0;
        for (int i=0;i<k;i++){ans+=cardPoints[i];}
        haha=ans;
        int x=k-1;
        for (int i=n-1;i>=n-k;i--){
            haha-=cardPoints[x];
            x--;
            haha+=cardPoints[i];
            ans=max(ans,haha);
        }
        return ans;
    }
};
