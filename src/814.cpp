// id:373926395
// runtime:4 ms
// memory:8.7 MB
// title:Binary Tree Pruning
// translatedTitle:二叉树剪枝
// questionId:832
// time:2022-10-17 20:09:49

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
    int dfs(TreeNode*x){
        int ret=x->val;
        if(x->left){
            int val=dfs(x->left);
            if(val)ret+=val;
            else x->left=nullptr;
        }
        if(x->right){
            int val=dfs(x->right);
            if(val)ret+=val;
            else x->right=nullptr;
        }
        return ret;
    }
    TreeNode* pruneTree(TreeNode* root) {
        int xs=dfs(root);
        if(xs==0)return nullptr;
        else return root;
    }
};