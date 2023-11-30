class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0 || k==nums.size() || nums.size()==1) return;
        k = k%nums.size();
        int done = 0;
        for(int i=0;;++i){
            int now = i;
            int temp = 0;
            int pre = nums[now];
            while(1){
                temp = nums[(now+k)%nums.size()];
                nums[(now+k)%nums.size()] = pre;
                now = (now+k)%nums.size();
                pre = temp;
                done++;
                if(now==i) break;
            }
            if(done==nums.size()) break;
        }
    }
};