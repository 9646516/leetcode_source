// id:373926286
// runtime:8 ms
// memory:9.1 MB
// title:二叉树剪枝
// translatedTitle:二叉树剪枝
// questionId:1000301
// time:2022-10-17 20:09:36

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