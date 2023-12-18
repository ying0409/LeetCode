class Solution {
public:
    void traverse(string &s, int now, vector<int> &dp){
        if (s[now] == '0') {
            dp[now] = 0;
            return ;
        }
        if (now == s.size() - 1 && s[now] != '0') {
            dp[now] = 1;
            return ;
        }
        if (now + 1 < s.size() && dp[now+1] == -1) traverse(s, now+1, dp);
        if ((s[now] - '0') * 10 + (s[now+1] - '0') < 27){
            if (now+2 < s.size()){
                if (dp[now+2] == -1) traverse(s, now+2, dp);
                dp[now] = dp[now+1] + dp[now+2];
            }
            else dp[now] = dp[now+1] + 1;
        }
        else dp[now] = dp[now+1];
    }
    int numDecodings(string s) {
        int start = 0;
        vector<int> dp(s.size(), -1);
        traverse(s, start, dp);
        return dp[0];
    }
};