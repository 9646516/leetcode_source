// id:374547065
// runtime:20 ms
// memory:16.2 MB
// title:First Common Ancestor LCCI
// translatedTitle:首个共同祖先
// questionId:100179
// time:2022-10-19 17:09:10

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
    int depp,depq;
    unordered_map<TreeNode*,TreeNode*>fa;
    void dfs(TreeNode*root,TreeNode*p,TreeNode*q,int d){
        if(root==p)depp=d;
        if(root==q)depq=d;
        if(root->left){
            fa[root->left]=root;
            dfs(root->left,p,q,d+1);
        }
        if(root->right){
            fa[root->right]=root;
            dfs(root->right,p,q,d+1);
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q,1);
        while(p!=q){
            if(depp>depq){
                p=fa[p];depp--;
            }else{
                q=fa[q];depq--;
            }
        }
        return q;
    }
};