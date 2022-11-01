// id:373927324
// runtime:8 ms
// memory:8.8 MB
// title:从根节点到叶节点的路径数字之和
// translatedTitle:从根节点到叶节点的路径数字之和
// questionId:1000306
// time:2022-10-17 20:12:04

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
    int ans=0;
    void dfs(TreeNode*x,int xs){
        if(!x->left&&!x->right){
            ans+=xs;
        }else{
            if(x->left)dfs(x->left,xs*10+x->left->val);
            if(x->right)dfs(x->right,xs*10+x->right->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,root->val);
        return ans;
    }
};