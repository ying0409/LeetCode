class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> s;
        s.push(root);
        while(s.size()!=0){
            vector<int> temp;
            int n = s.size();
            for(int i=0;i<n;++i){
                TreeNode* now = s.front();
                s.pop();
                temp.push_back(now->val);
                if(now->left) s.push(now->left);
                if(now->right) s.push(now->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};