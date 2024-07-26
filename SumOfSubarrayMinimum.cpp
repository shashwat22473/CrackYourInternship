const unsigned int M=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        vector<long long int> dis1(n);
        stack<pair<int,int>> st;
        st.push({-1e9,-1});
        for (int i=0;i<n;i++){
            while(st.top().first>=a[i]){
                st.pop();
            }
            dis1[i]=i-st.top().second;
            st.push({a[i],i});
        }
        vector<long long int> dis2(n);
        while(!st.empty()){st.pop();}
        st.push({-1e9,-1});
        reverse(a.begin(),a.end());
        for (int i=0;i<n;i++){
            while(st.top().first>a[i]){
                st.pop();
            }
            dis2[n-i-1]=i-st.top().second;
            st.push({a[i],i});
        }
        reverse(a.begin(),a.end());
        long long ans=0;
        for (int i=0;i<n;i++){
            cout<<dis1[i]<<" "<<dis2[i]<<endl;
        }
        for (int i=0;i<n;i++){
            ans+=((dis1[i]*dis2[i])%M*((long long ) a[i]))%M;
            ans%=M;
        }
        return ans;
    }
};
