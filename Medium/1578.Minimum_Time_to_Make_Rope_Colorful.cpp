class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        char pre = colors[0];
        int min_time = neededTime[0];
        for(int i=1; i<colors.size(); ++i) {
            if(colors[i] == pre) {
                if(neededTime[i] > min_time) {
                    ans += min_time;
                    min_time = neededTime[i];
                }
                else ans += neededTime[i];
            }
            else {
                pre = colors[i];
                min_time = neededTime[i];
            }
        }
        return ans;
    }
};