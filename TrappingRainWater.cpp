
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for (int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
            right[n-i-1]=max(height[n-i-1],right[n-i]);
        }
        int ans=0;
        for (int i=1;i<n-1;i++){
            ans+=max(min(left[i-1],right[i+1])-height[i],0);
        }
        return ans;
    }
};
