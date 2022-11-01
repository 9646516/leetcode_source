// id:377099737
// runtime:692 ms
// memory:149.6 MB
// title:二叉树染色
// translatedTitle:二叉树染色
// questionId:1000089
// time:2022-10-27 22:37:57

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using ll=long long;
class Solution {
public:
    int k;
    unordered_map<TreeNode*,ll>dp[11];
    ll dfs(TreeNode*x,int left){
        if(!x){
            if(left==0)return 0;
            return -1e10;
        }
        if(!x->left&&!x->right){
            if(left==0)return 0;
            if(left==1)return x->val;
            return -1e10;
        }        
        if(dp[left].count(x))return dp[left][x];
        if(left==0){
            ll ans=0;
            for(int i=0;i<=k;i++){
                for(int j=0;j<=k;j++){
                    ans=max(ans,dfs(x->left,i)+dfs(x->right,j));
                }
            }
            return dp[left][x]=ans;
        }
        ll ans=0;
        for(int i=0;i+1<=left;i++){
            ans=max(ans,dfs(x->left,i)+dfs(x->right,left-1-i));
        }
        return dp[left][x]=ans+x->val;
    }
    int maxValue(TreeNode* root, int k) {
        this->k=k;
        ll ans=0;
        for(int i=0;i<=k;i++){
            ans=max(ans,dfs(root,i));
        }
        return ans;
    }
};