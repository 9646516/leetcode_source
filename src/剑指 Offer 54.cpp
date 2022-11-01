// id:373633463
// runtime:12 ms
// memory:23.4 MB
// title:二叉搜索树的第k大节点  LCOF
// translatedTitle:二叉搜索树的第k大节点
// questionId:100333
// time:2022-10-16 21:40:52

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
    int ans;
    void dfs(TreeNode*x,int&k){
        if(x->right)dfs(x->right,k);
        k--;
        if(k==0){ans=x->val;return;}
        if(x->left)dfs(x->left,k);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
};