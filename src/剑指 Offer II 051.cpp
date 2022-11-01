// id:373940027
// runtime:72 ms
// memory:37.4 MB
// title:节点之和最大的路径
// translatedTitle:节点之和最大的路径
// questionId:1000309
// time:2022-10-17 20:40:48

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    unordered_map<TreeNode*,int>dp;
    unordered_map<TreeNode*,TreeNode*>fa;
    void dfs(TreeNode*x){
        int mx=0;
        if(x->left){
            fa[x->left]=x;
            dfs(x->left);
            mx=max(mx,dp[x->left]);
        }
        if(x->right){
            fa[x->right]=x;
            dfs(x->right);
            mx=max(mx,dp[x->right]);
        }
        dp[x]=x->val+mx;
    }
    void dfs2(TreeNode*x){
        ans=max(ans,dp[x]);
        if(x->left){
            int a=dp[x];
            int b=dp[x->left];
            {
                int mx=0;
                if(fa.count(x)){
                    mx=max(mx,dp[fa[x]]);
                }
                mx=max(mx,dp[x->right]);
                dp[x]=x->val+mx;
            }
            dp[x->left]=max(dp[x->left],x->left->val+max(0,dp[x]));
            dfs2(x->left);
            dp[x]=a;
            dp[x->left]=b;
        }
        if(x->right){
            int a=dp[x];
            int b=dp[x->right];
            {
                int mx=0;
                if(fa.count(x)){
                    mx=max(mx,dp[fa[x]]);
                }
                mx=max(mx,dp[x->left]);
                dp[x]=x->val+mx;
            }
            dp[x->right]=max(dp[x->right],x->right->val+max(0,dp[x]));
            dfs2(x->right);
            dp[x]=a;
            dp[x->right]=b;
        }
    }
    int maxPathSum(TreeNode* root) {
        ans=numeric_limits<int>::min();
        dfs(root);
        dfs2(root);
        return ans;
    }
};