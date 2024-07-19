#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long 
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        pbds oset;
        for(int i=0;i<nums.size();i++){
            oset.insert({nums[i],i});
        }
        vector<int> ans(nums.size());
        for (int i=0;i<nums.size();i++){
            int p=oset.order_of_key({nums[i],0});
            ans[i]=p;
            oset.erase({nums[i],i});
        }
        return ans;
        
    }
};
