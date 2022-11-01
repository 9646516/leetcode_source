// id:373664172
// runtime:28 ms
// memory:22.6 MB
// title:二叉树的最近公共祖先 LCOF
// translatedTitle:二叉树的最近公共祖先
// questionId:100347
// time:2022-10-16 23:23:04

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
    unordered_map<TreeNode*,int>dep;
    unordered_map<TreeNode*,TreeNode*>fa;
    void dfs(TreeNode*x,int d){
        dep[x]=d;
        if(x->left){
            fa[x->left]=x;
            dfs(x->left,d+1);
        }
        if(x->right){
            fa[x->right]=x;
            dfs(x->right,d+1);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,0);
        while(p!=q){
            if(dep[p]>dep[q]){
                p=fa[p];
            }else{
                q=fa[q];
            }
        }
        return q;
    }
};