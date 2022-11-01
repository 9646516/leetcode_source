// id:373309439
// runtime:12 ms
// memory:19.2 MB
// title:二叉树中和为某一值的路径 LCOF
// translatedTitle:二叉树中和为某一值的路径
// questionId:100317
// time:2022-10-15 21:26:01

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
    vector<vector<int>>ret;
    vector<int>now;
    void dfs(TreeNode*x,int xs){
        now.push_back(x->val);
        if(!x->left&&!x->right){
            if(xs-x->val==0)ret.push_back(now);
        }else{
            if(x->left)dfs(x->left,xs-x->val);
            if(x->right)dfs(x->right,xs-x->val);
        }
        now.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root)
            dfs(root,target);
        return ret;
    }
};