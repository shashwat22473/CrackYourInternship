class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> possible={{6,8},{7,9},{4,8},{3,10,9},{},{1,7,10},{2,6},{1,3},{2,4},{4,6}};
        vector<vector<long long >> arr(n,vector<long long> (11,0));

        for (int i=1;i<=10;i++){arr[0][i]=1LL;}
        for (int i=1;i<n;i++){
            for (int j=0;j<10;j++){
                for(int x:possible[j]){
                    arr[i][x]+=arr[i-1][j+1];
                    arr[i][x]%=1000000007;
                }

            }
        }
        long long int ans=0;
        for (int i=1;i<=10;i++){ans+=(int)arr[n-1][i];ans%=1000000007;}
        return (int)ans;

    }
};
