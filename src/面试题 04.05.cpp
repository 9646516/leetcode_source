// id:374541730
// runtime:8 ms
// memory:21.2 MB
// title:Legal Binary Search Tree LCCI
// translatedTitle:合法二叉搜索树
// questionId:100177
// time:2022-10-19 16:56:14

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ok;
    pair<int,int>dfs(TreeNode*x){
        if(!ok)return {0,0};
        int mn=x->val,mx=x->val;
        if(x->left){
            auto [a,b]=dfs(x->left);
            if(b>=x->val)ok=0;
            mn=min(mn,a);
        }
        if(x->right){
            auto [a,b]=dfs(x->right);
            if(a<=x->val)ok=0;
            mx=max(mx,b);
        }
        return {mn,mx};
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return 1;
        ok=1;
        dfs(root);
        return ok;
    }
};