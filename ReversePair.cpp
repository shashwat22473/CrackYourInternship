#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long 
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        pbds oset;
        int ans=0;
        oset.insert({nums[0],0});
        for (int i=1;i<nums.size();i++){
            int g=oset.order_of_key({2*((ll)nums[i])+1,0});
            ans+=(int)oset.size()- g;
            oset.insert({(ll)nums[i],i});

        } 
        return ans;
    }
};
