class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pointer=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==0){
                swap(nums[pointer],nums[i]);
                pointer++;
            }
        }
        for (int i=0;i<nums.size();i++){
            if (nums[i]==1){
                swap(nums[pointer],nums[i]);
                pointer++;
            }
        }

    }
};
