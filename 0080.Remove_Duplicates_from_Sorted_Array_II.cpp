class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int now = -10001;
        int count = 0;
        for(int i=0;i<nums.size();){
            if(now != nums[i]){
                now = nums[i];
                count = 0;
                count ++;
                ++i;
            }
            else{
                count ++;
                if(count>2){
                    int temp = nums[i];
                    nums.erase(nums.begin()+i);
                }
                else ++i;
            }
        }
        return nums.size();
    }
};